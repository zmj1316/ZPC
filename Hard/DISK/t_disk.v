`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:04:44 12/03/2015
// Design Name:   Disk
// Module Name:   F:/Workspace/ASM/Hard/DISK/t_disk.v
// Project Name:  DISK
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Disk
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_disk;

	// Inputs
	reg clk;
	reg RxD;
	reg Memread;
	reg Memwrite;
	reg [8:0] Addrin;

	// Outputs
	wire TxD;

	// Bidirs
	wire [31:0] BUS;

	// Instantiate the Unit Under Test (UUT)
	Disk uut (
		.clk(clk), 
		.TxD(TxD), 
		.RxD(RxD), 
		.BUS(BUS), 
		.Memread(Memread), 
		.Memwrite(Memwrite), 
		.Addrin(Addrin)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		RxD = 0;
		Memread = 0;
		Memwrite = 0;
		Addrin = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		Addrin = 9'h102;
		Memread = 1;
	end
   initial forever begin
		clk = ~clk;
		#2;
	
	end
endmodule

