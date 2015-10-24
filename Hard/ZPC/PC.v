`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:55:17 09/24/2015 
// Design Name: 
// Module Name:    PC 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module PC(clk_50mhz,vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,led
	,BUS,Memwrite,Memread,Addr
	,clk
    );
input wire clk_50mhz;//clock and reset signal
output vga_red, vga_green, vga_blue, vga_hsync, vga_vsync;//VGA signals
output reg led;
// input run;
output wire [31:0]BUS;//data BUS
output wire Memread;
output wire [1:0] Memwrite;
output wire [31:0] Addr;//Memory address
output reg clk;//CPU clock
//assign led = Memwrite[0];
//slow clock generator
reg [2:0]tmp;
initial clk = 0;
initial tmp = 0;
always @(posedge clk_50mhz) begin
	tmp = tmp + 1;
	if (tmp == 7) begin
		tmp = 0;
		clk = ~clk;
	end
end
always @(posedge Memwrite[0]) begin
	led=1;
end
CPU cpu(
	.clk(clk),
	.rst(rst),
	.BUS(BUS),
	.Memread(Memread),
	.Memwrite(Memwrite),
	.Addr(Addr)
	);
Mem16 mem(
	.clk(clk_50mhz),
	.BUS(BUS),
	.Memread(Memread),
	.Memwrite((Addr[31:28] == 4'hA)?2'b0:Memwrite),
	.Addrin(Addr[31:0])
	);

wire VMwrite;// signal for Video memory write
assign VMwrite = (Addr[31:28] == 4'hA)?Memwrite[0]:0;
// VGA vga(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,clk_50mhz,rst,BUS,0,{4'b0,Addr[27:0]});
VGA vga(
	.vga_red(vga_red),
	.vga_green(vga_green),
	.vga_blue(vga_blue),
	.vga_hsync(vga_hsync),
	.vga_vsync(vga_vsync),
	.clk_50mhz(clk_50mhz),
	.BUS(BUS),
	.Memwrite(VMwrite),
	.Addrin(Addr[27:0])
	);
endmodule
