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
	,clk,TxD,RxD,INTin
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
//assign led = Memwrite[0];
//slow clock generator
reg [2:0]tmp;
integer i = 0;
initial clk = 0;
initial tmp = 0;
always @(posedge clk_50mhz) begin
	tmp = tmp + 1;
	if (tmp == 7) begin
		tmp = 0;
		clk = ~clk;
	end
end

output reg INTin;
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
	.read(keyread),
	.TxD(TxD),
	.RxD(RxD)
	);
// ps2scan ps2(
// 	.clk(clk_50mhz),
// 	.rst_n(1),
// 	.ps2k_clk(),
// 	.ps2k_data(),
// 	.ps2_byte(),
// 	.ps2_state()
// 	);
initial begin
	INTin = 0;
end
always @(posedge clk_50mhz) begin
	i = i+1;
end
always @(clk_50mhz) begin
	INTin = 0;
	// if (i>300) begin
	// 	INTin = 1'b1;
	// 	INTnum = 1;
	// end
	// if (i>310) begin
	// 	INTin = 0;
	// end
	// if (i>400) begin
	// 	INTin = 1;
	// end
	// if (i>420) begin
	// 	INTin=0;
	// end
	if (keypress) begin
		INTin = 1;
		INTnum = 1;
	end
end
endmodule
