`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:07:07 09/18/2015
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
	reg [31:0] Memin;

	// Outputs
	wire [31:0] Memout;
	wire Memread;
	wire Memwrite;
	wire [31:0] Addr;
	wire [31:0] Regtest;
	wire [31:0] PC;
	wire [2:0] stage;
	wire [12:0] signal;
	wire [31:0] MDR;

	// Instantiate the Unit Under Test (UUT)
	CPU uut (
		.clk(clk), 
		.rst(rst), 
		.Memin(Memin), 
		.Memout(Memout), 
		.Memread(Memread), 
		.Memwrite(Memwrite), 
		.Addr(Addr), 
		.Regtest(Regtest), 
		.PC(PC), 
		.stage(stage), 
		.signal(signal), 
		.MDR(MDR)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		Memin = 32'h8C010000;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
   initial forever begin
		#10;
		clk = ~clk;
		if(stage > 5) begin
			Memin = 32'hac010000;
		end
	end
endmodule

