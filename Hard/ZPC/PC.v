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
module PC(clk,vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,rst
    );
input wire clk,rst;
output vga_red, vga_green, vga_blue, vga_hsync, vga_vsync;

wire [31:0]BUS;
wire Memread;
wire [1:0] Memwrite;
wire [31:0] Addr;
CPU cpu(
	.clk(clk),
	.rst(rst),
	.BUS(BUS),
	.Memread(Memread),
	.Memwrite(Memwrite),
	.Addr(Addr)
	);
Mem mem(
	.clk(clk),
	.BUS(BUS),
	.Memread(Memread),
	.Memwrite(Memwrite),
	.Addrin(Addr)
	);
VGA vga(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,clk,rst);

endmodule
