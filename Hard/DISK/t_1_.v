`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:13:09 12/03/2015
// Design Name:   tt_Disk
// Module Name:   F:/Workspace/ASM/Hard/DISK/t_1_.v
// Project Name:  DISK
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: tt_Disk
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_1_;

	// Inputs
	reg clk;
	reg RxD;
	reg signal;
	// Outputs
	wire TxD;

	// Instantiate the Unit Under Test (UUT)
	tt_Disk uut (
		.clk(clk), 
		.TxD(TxD), 
		.RxD(RxD),
		.signal(signal)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		RxD = 0;

		// Wait 100 ns for global reset to finish
		#100;
      signal = 1;
		#20;
		signal = 0;
		// Add stimulus here

	end
   initial forever begin
		clk = ~clk;
		#2;
	
	end
endmodule

