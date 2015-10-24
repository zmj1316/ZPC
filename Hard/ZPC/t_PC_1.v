`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:39:09 10/21/2015
// Design Name:   PC
// Module Name:   F:/Workspace/ASM/Hard/ZPC/t_PC_1.v
// Project Name:  ZPC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: PC
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_PC_1;

	// Inputs
	reg clk_50mhz;

	// Outputs
	wire vga_red;
	wire vga_green;
	wire vga_blue;
	wire vga_hsync;
	wire vga_vsync;
	wire led;
	wire clk;

	// Instantiate the Unit Under Test (UUT)
	PC uut (
		.clk_50mhz(clk_50mhz), 
		.vga_red(vga_red), 
		.vga_green(vga_green), 
		.vga_blue(vga_blue), 
		.vga_hsync(vga_hsync), 
		.vga_vsync(vga_vsync), 
		.led(led), 
		.clk(clk)
	);

	initial begin
		// Initialize Inputs
		clk_50mhz = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
   initial forever begin
	#5;
	clk_50mhz = ~clk_50mhz;
	end
      
endmodule

