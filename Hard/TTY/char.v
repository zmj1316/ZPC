`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:20:21 09/23/2015 
// Design Name: 
// Module Name:    char 
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
module char(c,x,y,d,clk
    );
input [7:0] c;
input [3:0] x;
input [3:0] y;
output reg d;
input clk;

wire [15:0] douta;
CM cm(
	.addra({c[7:0],y[3:0]}),
	.clka(clk),
	.douta(douta)
);
// assign d = douta[15-x];
always @(posedge clk ) begin
		d = douta[15-x];
	end	
endmodule
