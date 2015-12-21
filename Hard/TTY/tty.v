`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:24:39 11/15/2015 
// Design Name: 
// Module Name:    tty 
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
module tty(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,clk_50mhz,ps2_clk,ps2_data,
			BUS,write,read,keypress
			// ,TxD,RxD
			// ,writeback,readback
    );
output vga_red, vga_green, vga_blue, vga_hsync, vga_vsync;
input clk_50mhz;
inout ps2_clk,ps2_data;
inout [31:0]BUS;
input read ,write;
output keypress;
//output reg[7:0] GPout = 0;
reg [7:0] readdata = 8'h41;
reg VMwrite;
wire ttywrite;
wire [7:0] ascii;
wire released;
reg [7:0] ascdata;
// reg TxD_start=0;
// reg [7:0] TxD_data = 8'h0;
// output TxD;
// input RxD;
// wire TxD_busy;
// wire RxD_data_ready;
// wire [7:0] RxD_data;

assign BUS = read?{0,readdata}:32'bz;
assign keypress = released;
reg [7:0] writedata;

// reg [31:0] i = 32'h0;
// output reg [7:0] IDEstate = 8'h0;
// reg signal = 0;

VGA vga(
	.vga_red(vga_red),
	.vga_green(vga_green),
	.vga_blue(vga_blue),
	.vga_hsync(vga_hsync),
	.vga_vsync(vga_vsync),
	.clk_50mhz(clk_50mhz),
	.BUS(writedata),
	.Memwrite(VMwrite),
	.ttywrite(ttywrite)
	// .Addrin({0,Addr[3:0]})
	);

ps2_keyboard_interface kb(
	.clk(clk_50mhz),
	.ps2_clk(ps2_clk),
	.ps2_data(ps2_data),
	.rx_ascii(ascii),
	.rx_released(released)
	);


always @(posedge clk_50mhz) begin
	readdata = ascii;
	if (write == 1) begin
		VMwrite = 1;
		writedata = BUS[7:0];
	end
	else if (released == 1) begin
		readdata = ascii;
		VMwrite = 1;
		writedata = ascii;
	end
	else begin
		VMwrite = 0;
	end
end
endmodule
