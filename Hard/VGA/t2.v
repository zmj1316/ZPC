`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:01:26 10/09/2015
// Design Name:   VGA
// Module Name:   F:/Workspace/ASM/Hard/VGA/t2.v
// Project Name:  VGA
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

module t2;

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
	wire [7:0] doutb;
	wire [10:0] h_counter;

	// Bidirs
	wire [31:0] BUS;

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
		.doutb(doutb), 
		.h_counter(h_counter)
	);

	initial begin
		// Initialize Inputs
		clk_50mhz = 0;
		Memwrite = 0;
		Addrin = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      initial forever begin
	
		clk_50mhz = ~clk_50mhz;
		#5;
	end
endmodule

