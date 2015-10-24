`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:41:27 10/15/2015
// Design Name:   Mem
// Module Name:   F:/Workspace/ASM/Hard/ZPC/t_mem.v
// Project Name:  ZPC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Mem
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_mem;

	// Inputs
	reg clk;
	reg Memread;
	reg [1:0] Memwrite;
	reg [11:0] Addrin;
	reg rst;

	// Bidirs
	wire [31:0] BUS;

	// Instantiate the Unit Under Test (UUT)
	Mem uut (
		.clk(clk), 
		.BUS(BUS), 
		.Memread(Memread), 
		.Memwrite(Memwrite), 
		.Addrin(Addrin), 
		.rst(rst)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		Memread = 1;
		Memwrite = 0;
		Addrin = 0;
		rst = 0;

		// Wait 100 ns for global reset to finish
		#100;
      Addrin = Addrin + 1;
		// Add stimulus here
		#100;
      Addrin = Addrin + 1;
		#100;
      Addrin = Addrin + 1;

	end
      initial forever begin
			#5;
			clk = ~clk;
		end
endmodule

