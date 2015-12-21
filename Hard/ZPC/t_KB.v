`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:01:31 12/21/2015
// Design Name:   PC
// Module Name:   F:/Workspace/ASM/Hard/ZPC/t_KB.v
// Project Name:  ZPC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: PC
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_KB;

	// Inputs
	reg clk_50mhz;
	reg RxD;

	// Outputs
	wire vga_red;
	wire vga_green;
	wire vga_blue;
	wire vga_hsync;
	wire vga_vsync;
	wire [31:0] BUS;
	wire [1:0] Memwrite;
	wire Memread;
	wire [31:0] Addr;
	wire clk;
	wire TxD;
	wire INTin;

	// Bidirs
	wire ps2_clk;
	wire ps2_data;

	// Instantiate the Unit Under Test (UUT)
	PC uut (
		.clk_50mhz(clk_50mhz), 
		.vga_red(vga_red), 
		.vga_green(vga_green), 
		.vga_blue(vga_blue), 
		.vga_hsync(vga_hsync), 
		.vga_vsync(vga_vsync), 
		.ps2_clk(ps2_clk), 
		.ps2_data(ps2_data), 
		.BUS(BUS), 
		.Memwrite(Memwrite), 
		.Memread(Memread), 
		.Addr(Addr), 
		.clk(clk), 
		.TxD(TxD), 
		.RxD(RxD), 
		.INTin(INTin)
	);
	reg c2=0;
	assign ps2_clk = c2;
	assign ps2_data = c2;
	initial begin
		// Initialize Inputs
		clk_50mhz = 0;
		RxD = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
   initial forever begin
	#5;
	clk_50mhz = ~clk_50mhz;
	end
	initial forever begin
	#50;
	c2 = ~c2;
	end
endmodule

