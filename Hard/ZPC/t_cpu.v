`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:51:52 10/15/2015
// Design Name:   CPU
// Module Name:   F:/Workspace/ASM/Hard/ZPC/t_cpu.v
// Project Name:  ZPC
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

module t_cpu;

	// Inputs
	reg clk;
	reg rst;
	reg INTin;
	reg [31:0] INTnum;

	// Outputs
	wire Memread;
	wire [1:0] Memwrite;
	wire [31:0] Addr;

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
		.INTin(INTin), 
		.INTnum(INTnum)
	);
	reg [31:0] Memin;
	assign BUS = Memread?Memin:32'bz;
	initial begin
		// Initialize Inputs
		Memin = 32'b00111100000100001010000000000000;
		clk = 0;
		rst = 0;
		INTin = 0;
		INTnum = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		Memin = 32'b10101110000100010000000000000000;
		#500000;
		INTin = 1;
		INTnum = 1;
	end
   initial forever begin
		#5;
		clk=~clk;
	
	end
endmodule

