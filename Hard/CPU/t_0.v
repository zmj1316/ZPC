`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:23:31 09/22/2015
// Design Name:   CPU
// Module Name:   F:/Workspace/ASM/Hard/CPU/t_0.v
// Project Name:  CPU
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CPU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_0;

	// Inputs
	reg clk;
	reg rst;

	// Outputs
	wire Memread;
	wire Memwrite;
	wire [31:0] Addr;
	wire [31:0] A;
	wire RegT;

	// Bidirs
	wire [31:0] BUS;

	// Instantiate the Unit Under Test (UUT)
	CPU uut (
		.clk(clk), 
		.rst(rst), 
		.BUS(BUS), 
		.Memread(Memread), 
		.Memwrite(Memwrite), 
		.Addr(Addr), 
		.A(A), 
		.RegT(RegT)
	);
	reg [31:0] Memin;
	assign BUS = Memread?Memin:32'bz;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		Memin = 32'b00100000001000010000000011101001;
		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
   initial forever begin 
		#10;
		clk=~clk;
	end
endmodule

