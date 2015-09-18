`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:51:55 09/17/2015 
// Design Name: 
// Module Name:    IFS 
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
// (C) 2015 Key Zhang 
//////////////////////////////////////////////////////////////////////////////////
module IFS(clk,PC,Mem,
			Memread,Addr,
			PCo,OP,RS,RT,RD,shamt,func,imme,
			rst
    );
input wire clk;

input wire [31:0] PC;
input wire [31:0] Mem;

output reg Memread;
output reg [31:0] Addr;

output reg [31:0] PCo;
output reg [5:0] OP;
output reg [4:0] RS;
output reg [4:0] RT;
output reg [4:0] RD;
output reg [4:0] shamt;
output reg [5:0] func;
output reg [15:0] imme;

input wire rst;

always @(posedge clk or posedge rst) begin
	if (rst) begin
		// reset
		
	end
	else if(Memread == 0)begin
		Addr = PC;
		Memread = 1;
	end
	else begin
		PCo = PC + 4;
		OP = (Mem >> 26) & 6'h3F;
		RS = (Mem >> 21) & 5'h1F;
		RT = (Mem >> 16) & 5'h1F;
		RD = (Mem >> 11) & 5'h1F;
		shamt = (Mem >> 6) & 5'h1F;
		func = Mem & 6'h3F;
		imme = Mem & 16'hFFFF;
		Memread = 0;
	end
end
endmodule
