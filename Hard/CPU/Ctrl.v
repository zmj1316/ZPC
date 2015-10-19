`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:17:39 09/18/2015 
// Design Name: 
// Module Name:    Ctrl 
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
module Ctrl(input wire [5:0] OP,output reg [13:0] signal
    );
/* signal define:
 * 13:Membyte? 12:ALUOP 11:SA 10-9:SB 8-7:RegDst 6:Mem2Reg 5:RegW 
 * 4:MemR 3:MemW 2:PC_S 1:PCWC 0:PCW
 */
always @(*) begin
	case(OP)
		6'h0:  signal = 14'b01100010100000;//R
		6'h2:  signal = 14'b00011000000001;//J
		6'h3:  signal = 14'b00011100100101;//JAL
		6'h4, 
		6'h5:  signal = 14'b00011000000010;//beq bne
		6'h8:  signal = 14'b00110000100000;//ADDI
		6'h23: signal = 14'b00110001110000;//LW
		6'h2B: signal = 14'b00110000001000;//SW
		6'h20: signal = 14'b10110001110000; //LB
		6'h28: signal = 14'b10110000001000; //SB
		// 6'h10: signal = 14'b00110000100000;//CO
		//I-Type
		default: signal = 14'b00110000100000;//I-type
	endcase
end
// assign signal = 
// (OP == 6'h0)? 14'b01100010100000:
// (OP == 6'h2)? 14'b00011000000001:
// (OP == 6'h3)? 14'b00011100100101:
// (OP ==6'h4||OP == 6'h5)? 14'b00011000000010:
// (OP == 6'h8)? 14'b00110000100000:
// (OP == 6'h20)? 14'b10110001110000: //LB
// (OP == 6'h28)? 14'b10110000001000: //SB
// (OP == 6'h23)? 14'b00110001110000:
// (OP == 6'h2B)? 14'b00110000001000:
// 14'b00110000100000;
endmodule
