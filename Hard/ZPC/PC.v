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
module PC(clk_50mhz,vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,rst,led
    );
input wire clk_50mhz,rst;//clock and reset signal
output vga_red, vga_green, vga_blue, vga_hsync, vga_vsync;//VGA signals
output reg led;
// input run;
wire [31:0]BUS;//data BUS
wire Memread;
wire [1:0] Memwrite;
wire [31:0] Addr;//Memory address
wire clk;//CPU clock
//assign led = Memwrite[0];
//slow clock generator
reg [2:0]tmp;
always @(posedge clk_50mhz or posedge rst) begin
	if (rst) begin
		// reset
		tmp = 0;
	end
	else begin
		tmp =tmp+1;
	end
end
assign clk = tmp[2];
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
Mem mem(
	.clk(clk_50mhz),
	.BUS(BUS),
	.Memread(Memread),
	.Memwrite(Memwrite),
	.Addrin(Addr[11:0])
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
