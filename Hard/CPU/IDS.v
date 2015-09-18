`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:06:01 09/17/2015 
// Design Name: 
// Module Name:    IDS 
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
module IDS(clk,PC,
			OP,RS,RT,RD,shamt,func,imme,
			Dst,RA,RB,immeo,PCo,
			Regfile,
			// RegDst,
			rst
    );
input wire clk;

input wire [31:0] PC;
input wire [5:0] OP;
input wire [4:0] RS;
input wire [4:0] RT;
input wire [4:0] RD;
input wire [4:0] shamt;
input wire [5:0] func;
input wire [15:0] imme;

output reg [4:0] Dst;
output reg [31:0] RA;
output reg [31:0] RB;
output reg [31:0] immeo;
output reg [31:0] PCo;

// input wire [1:0] RegDst;
reg [31:0]Regfile[31:0];
input wire rst;

reg [12:0] signal;
Ctrl C(OP,signal);

always @(posedge clk or posedge rst) begin
	if (rst) begin
		// reset
		
	end
	else begin
		RA = Regfile[RS];
		RB = Regfile[RT];
		case(signal[5:4])
			2'b0: Dst = RT;
			2'b1: Dst = RS;
			2'b10: Dst = 5'h1F;
		endcase
		immeo = {{16{imme[15]}},imme[15:0]};
		PCo = PC;
	end
end
endmodule
