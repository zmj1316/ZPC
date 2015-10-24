`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:10:32 10/19/2015 
// Design Name: 
// Module Name:    NewMem 
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
module NewMem(clk,BUS,Memread,Memwrite,Addrin,rst
    );
input clk;// memory clock
inout [31:0] BUS;// data BUS
input Memread;
input [1:0] Memwrite;
input [11:0] Addrin;
input rst;
reg we;
initial we = 0;
reg [27:0] addr0;
reg [27:0] addr1;

reg [15:0] data0;
reg [15:0] data1;

wire [15:0] out0;
wire [15:0] out1;

halfWordBank bank0(
	.clka(clk),
	.wea(we),
	.addra(addr0),
	.dina(data0),
	.douta(out0)
);

halfWordBank bank1(
	.clka(clk),
	.wea(we),
	.addra(addr1),
	.dina(data1),
	.douta(out1)
);

always @(posedge clk) begin
	
end

endmodule
