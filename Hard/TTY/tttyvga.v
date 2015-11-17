`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:48:34 11/15/2015
// Design Name:   VGA
// Module Name:   F:/Workspace/ASM/Hard/TTY/tttyvga.v
// Project Name:  TTY
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: VGA
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tttyvga;

	// Inputs
	reg clk_50mhz;
	reg Memwrite;
	reg [31:0] Addrin;

	// Outputs
	wire vga_red;
	wire vga_green;
	wire vga_blue;
	wire vga_hsync;
	wire vga_vsync;

	// Bidirs
	wire [31:0] BUS;
	
	wire [7:0] doutb;
	wire [7:0] cur;
	// Instantiate the Unit Under Test (UUT)
	VGA uut (
		.vga_red(vga_red), 
		.vga_green(vga_green), 
		.vga_blue(vga_blue), 
		.vga_hsync(vga_hsync), 
		.vga_vsync(vga_vsync), 
		.clk_50mhz(clk_50mhz), 
		.BUS(BUS), 
		.Memwrite(Memwrite), 
		.Addrin(Addrin),
		.cur(cur)
	);

endmodule

