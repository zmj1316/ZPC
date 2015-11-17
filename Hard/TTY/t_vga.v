`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:22:41 11/15/2015
// Design Name:   VGA
// Module Name:   F:/Workspace/ASM/Hard/TTY/t_vga.v
// Project Name:  TTY
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: VGA
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module t_vga;

	// Inputs
	reg clk_50mhz;
	reg Memwrite;
	reg [31:0] Addrin;

	// Outputs
	wire vga_red;
	wire vga_green;
	wire vga_blue;
	wire vga_hsync;
	wire vga_vsync;
	wire [7:0] doutb;
	wire [7:0] cur;
	wire ttyWFlag;
	wire ttywrite;
	wire [7:0] ttydata;
	wire [10:0] h_counter;
	// Bidirs
	wire [31:0] BUS;
	wire clk_25mhz;
	// Instantiate the Unit Under Test (UUT)
	VGA uut (
		.vga_red(vga_red), 
		.vga_green(vga_green), 
		.vga_blue(vga_blue), 
		.vga_hsync(vga_hsync), 
		.vga_vsync(vga_vsync), 
		.clk_50mhz(clk_50mhz), 
		.BUS(BUS), 
		.Memwrite(Memwrite), 
		.Addrin(Addrin), 
		.doutb(doutb), 
		.cur(cur), 
		.ttyWFlag(ttyWFlag), 
		.ttywrite(ttywrite), 
		.ttydata(ttydata),
		.clk_25mhz(clk_25mhz),
		.h_counter(h_counter)
	);

	reg [31:0] Memin;
	assign BUS = 1?Memin:32'bz;
	initial begin
		// Initialize Inputs
		clk_50mhz = 0;
		Memwrite = 0;
		Addrin = 0;
		Memin = 1;
		// Wait 100 ns for global reset to finish
		#100;
		// Add stimulus here
	end
      
	initial forever begin
		#5;
		clk_50mhz = ~ clk_50mhz;
	end
	always @(posedge clk_25mhz) begin
			Memin = Memin + 1;
	if(Memin[0] == 0) begin
		Memwrite = 1;
	end
	else Memwrite = 0;
	end
      
endmodule

