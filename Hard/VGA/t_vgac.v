`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:57:40 10/09/2015
// Design Name:   vga_controller_640_60
// Module Name:   F:/Workspace/ASM/Hard/VGA/t_vgac.v
// Project Name:  VGA
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: vga_controller_640_60
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_vgac;

	// Inputs
	reg pixel_clk;

	// Outputs
	wire HS;
	wire VS;
	wire [10:0] hcounter;
	wire [10:0] vcounter;
	wire blank;

	// Instantiate the Unit Under Test (UUT)
	vga_controller_640_60 uut (
		.pixel_clk(pixel_clk), 
		.HS(HS), 
		.VS(VS), 
		.hcounter(hcounter), 
		.vcounter(vcounter), 
		.blank(blank)
	);

	initial begin
		// Initialize Inputs
		pixel_clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      initial forever begin
		
			pixel_clk = ~pixel_clk;#5;
		
		end
endmodule

