`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:47:23 12/02/2015
// Design Name:   tty
// Module Name:   F:/Workspace/ASM/Hard/TTY/t_tty.v
// Project Name:  TTY
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: tty
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_tty;

	// Inputs
	reg clk_50mhz;
	reg write;
	reg read;
	reg RxD;

	// Outputs
	wire vga_red;
	wire vga_green;
	wire vga_blue;
	wire vga_hsync;
	wire vga_vsync;
	wire keypress;
	wire TxD;

	// Bidirs
	wire ps2_clk;
	wire ps2_data;
	wire [7:0] IDEstate;

	// Instantiate the Unit Under Test (UUT)
	tty uut (
		.vga_red(vga_red), 
		.vga_green(vga_green), 
		.vga_blue(vga_blue), 
		.vga_hsync(vga_hsync), 
		.vga_vsync(vga_vsync), 
		.clk_50mhz(clk_50mhz), 
		.ps2_clk(ps2_clk), 
		.ps2_data(ps2_data), 
		.IDEstate(IDEstate), 
		.write(write), 
		.read(read), 
		.keypress(keypress), 
		.TxD(TxD), 
		.RxD(RxD)
	);

	initial begin
		// Initialize Inputs
		clk_50mhz = 0;
		write = 0;
		read = 0;
		RxD = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
   initial forever begin
		#5;
		clk_50mhz = ~clk_50mhz;
	end
endmodule

