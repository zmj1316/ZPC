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
module Ctrl(input wire [5:0] OP,output wire [12:0] signal
    );
/* signal define:
 * 12:ALUOP 11:SA 10-9:SB 8-7:RegDst 6:Mem2Reg 5:RegW 
 * 4:MemR 3:MemW 2:PC_S 1:PCWC 0:PCW
 */
// always @(*) begin
// 	case(OP)
// 		6'h0: signal = 13'b1100010100000;//R
// 		6'h2: signal = 13'b0011000000001;//J
// 		6'h3: signal = 13'b0011100100101;//JAL
// 		6'h4,6'h5:signal = 13'b0011000000010;//beq bne
// 		6'h8: signal = 13'b0110000100000;//ADDI
// 		6'h23: signal = 13'b0110001110000;//LW
// 		6'h2B: signal = 13'b0110000001000;//SW
// 		//I-Type
// 		default: signal = 13'b0110000100000;//I-type
// 	endcase
// end
assign signal = 
(OP == 6'h0)? 13'b1100010100000:
(OP == 6'h2)? 13'b0011000000001:
(OP == 6'h3)? 13'b0011100100101:
(OP ==6'h4||OP == 6'h5)? 13'b0011000000010:
(OP == 6'h8)? 13'b0110000100000:
(OP == 6'h23)? 13'b0110001110000:
(OP == 6'h2B)? 13'b0110000001000:
13'b0110000100000;
endmodule
