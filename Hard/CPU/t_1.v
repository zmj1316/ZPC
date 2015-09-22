`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:36:29 09/22/2015
// Design Name:   CPU
// Module Name:   F:/Workspace/ASM/Hard/CPU/t_1.v
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

module t_1;

	// Inputs
	reg clk;
	reg rst;

	// Outputs
	wire Memread;
	wire Memwrite;
	wire [31:0] Addr;
	wire [31:0] A;
	wire [31:0] PC;
	wire [31:0] IR;
	wire [31:0] Alures;

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
		.PC(PC), 
		.IR(IR), 
		.Alures(Alures)
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
		#80;
		Memin = 32'b10101100000000010000000001111011;
		#80;
		Memin = 32'b00001000000000000000000000000000;
	end
   initial forever begin 
		#10;
		clk=~clk;
	end
   
endmodule

