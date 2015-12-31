`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:09:59 12/31/2015
// Design Name:   Disk
// Module Name:   F:/Workspace/ASM/Hard/ZPC/t_com.v
// Project Name:  ZPC
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

module t_com;

	// Inputs
	reg clk;
	reg RxD;
	reg Memread;
	reg Memwrite;
	reg [9:0] Addrin;
	reg debug;
	reg [31:0] PC;
	reg [31:0] IR;

	// Outputs
	wire TxD;
	wire Busy;
	wire [9:0] Rstate;
	wire [15:0] Tstate;
	wire TxD_busy;
	wire TxD_start;

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
		.Addrin(Addrin), 
		.debug(debug), 
		.PC(PC), 
		.IR(IR), 
		.Busy(Busy), 
		.Rstate(Rstate), 
		.Tstate(Tstate), 
		.TxD_busy(TxD_busy), 
		.TxD_start(TxD_start)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		RxD = 0;
		Memread = 0;
		Memwrite = 0;
		Addrin = 0;
		debug = 0;
		PC = 0;
		IR = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		debug = 1;
		#20;
		debug=0;
	end
   initial forever begin
	#5;
		clk = ~clk;
	end
endmodule

