`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:55:17 09/24/2015 
// Design Name: 
// Module Name:    PC 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module PC(clk_50mhz,vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,ps2_clk,ps2_data
	,BUS,Memwrite,Memread,Addr
	,clk,TxD,RxD,lcd_rs,lcd_rw,lcd_e,sf_d,led,led0
	
    );
input wire clk_50mhz;//clock and reset signal
output vga_red, vga_green, vga_blue, vga_hsync, vga_vsync;//VGA signals
// input run;
output wire [31:0]BUS;//data BUS
output wire Memread;
output wire [1:0] Memwrite;
output wire [31:0] Addr;//Memory address
output reg clk;//CPU clock

inout wire ps2_clk;
inout wire ps2_data;
output TxD;
input RxD;
output lcd_rs;
output lcd_rw;
output lcd_e;
output [11:8] sf_d;
reg [7:0] char_mem_bus = 8'h20;
wire [4:0] char_mem_addr;
lcd lcd (clk_50mhz, lcd_rs, lcd_rw, lcd_e, sf_d, char_mem_addr, char_mem_bus);
output reg led;
output reg led0;
//assign led = Memwrite[0];
//slow clock generator
reg [2:0]tmp;
initial clk = 0;
initial tmp = 0;
always @(posedge clk_50mhz) begin
	tmp = tmp + 1;
	if (tmp == 7) begin
		tmp = 0;
		clk = ~clk;
	end
end

reg INTin;
reg [31:0]INTnum;
CPU cpu(
	.clk(clk),
	.rst(rst),
	.BUS(BUS),
	.Memread(Memread),
	.Memwrite(Memwrite),
	.Addr(Addr),
	.INTin(INTin),
	.INTnum(INTnum)
	);
Mem16 mem(
	.clk(clk_50mhz),
	.BUS(BUS),
	.Memread((Addr[31:28] == 4'h0)?Memread:0),
	.Memwrite((Addr[31:28] == 4'h0)?Memwrite:0),
	// .Memwrite(0),
	.Addrin(Addr[31:0])
	);
Disk disk(
	.clk(clk_50mhz),
	.TxD(TxD),
	.RxD(RxD),
	.BUS(BUS),
	.Memread((Addr[31:28]==4'hD)?Memread:1'b0),
	.Memwrite((Addr[31:28]==4'hD)?Memwrite[0]:1'b0),
	.Addrin(Addr)
	);
wire VMwrite;// signal for Video memory write
assign VMwrite = (Addr[31:28] == 4'hA)?Memwrite[0]:0;
wire keyread;
assign keyread = (Addr[31:28] == 4'hB)?Memread:0;
// VGA vga(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,clk_50mhz,rst,BUS,0,{4'b0,Addr[27:0]});
// VGA vga(
// 	.vga_red(vga_red),
// 	.vga_green(vga_green),
// 	.vga_blue(vga_blue),
// 	.vga_hsync(vga_hsync),
// 	.vga_vsync(vga_vsync),
// 	.clk_50mhz(clk_50mhz),
// 	.BUS(BUS),
// 	.Memwrite(VMwrite),
// 	.Addrin({0,Addr[3:0]})
// 	);
wire keypress;
tty t(
	.vga_red(vga_red),
	.vga_green(vga_green),
	.vga_blue(vga_blue),
	.vga_hsync(vga_hsync),
	.vga_vsync(vga_vsync),
	.clk_50mhz(clk_50mhz),
	.ps2_clk(ps2_clk),
	.ps2_data(ps2_data),
	.BUS(BUS),
	.keypress(keypress),
	.write(VMwrite),
	.read(keyread)
	);
// ps2scan ps2(
// 	.clk(clk_50mhz),
// 	.rst_n(1),
// 	.ps2k_clk(),
// 	.ps2k_data(),
// 	.ps2_byte(),
// 	.ps2_state()
// 	);
reg keypressFlag=1'b0;
initial begin
	INTin = 0;
	keypressFlag=1'b0;
end
always @(clk_50mhz) begin
	if (keypress==1'b1 && keypressFlag == 0) begin
		INTin = 1;
		INTnum = 1;
		keypressFlag = 1;
	end
	if (keypress == 1) begin
		keypressFlag = 1;
	end
	if (keypress == 0) begin
		keypressFlag = 0;
	end
	if (keyread) begin
		INTin = 0;
	end
	led0 = INTin;
	led = keypress;
end
endmodule

module lcd (
	input            clk,
	output reg       lcd_rs,
	output reg       lcd_rw,
	output reg       lcd_e,
	output reg [7:4] lcd_d,
	output     [4:0] mem_addr,
	input      [7:0] mem_bus
	);
	
	parameter        n = 24;
	parameter        j = 17;           // Initialization is slow, runs at clk/2^(j+2) ~95Hz
	parameter        k = 11;           // Writing/seeking is fast, clk/2^(k_2) ~6KHz
	parameter        noop = 6'b010000; // Allows LCD to drive lcd_d, can be safely written any time
	
	reg        [n:0] count = 0;
	reg        [5:0] lcd_state = noop;
	reg              init = 1;         // Start in initialization on power on
	reg              row = 0;          // Writing to top or or bottom row
	
	assign mem_addr = {row, count[k+6:k+3]};
	
	initial count[j+7:j+2] = 11;

	always @ (posedge clk) begin
		count <= count + 1;
		if (init) begin                    // initalization
			case (count[j+7:j+2])
				1: lcd_state <= 6'b000010;    // function set
				2: lcd_state <= 6'b000010;
				3: lcd_state <= 6'b001000;
				4: lcd_state <= 6'b000000;    // display on/off control
				5: lcd_state <= 6'b001100;
				6: lcd_state <= 6'b000000;    // display clear
				7: lcd_state <= 6'b000001;
				8: lcd_state <= 6'b000000;    // entry mode set
				9: lcd_state <= 6'b000110;
				10: begin init <= ~init; count <= 0; end
			endcase
			// Write lcd_state to the LCD and turn lcd_e high for the middle half of each lcd_state
			{lcd_e,lcd_rs,lcd_rw,lcd_d[7:4]} <= {^count[j+1:j+0] & ~lcd_rw,lcd_state}; 
		end else begin                                                              // Continuously update screen from memory
			case (count[k+7:k+2]) 
				32: lcd_state <= {3'b001,~row,2'b00};                                 // Move cursor to begining of next line
				33: lcd_state <= 6'b000000;
				34: begin count <= 0; row <= ~row; end                                // Restart and switch which row is being written
				default: lcd_state <= {2'b10, ~count[k+2] ? mem_bus[7:4] : mem_bus[3:0]}; // Pull characters from bus
			endcase
			// Write lcd_state to the LCD and turn lcd_e high for the middle half of each lcd_state
			{lcd_e,lcd_rs,lcd_rw,lcd_d[7:4]} <= {^count[k+1:k+0] & ~lcd_rw,lcd_state};
		end
	end
endmodule