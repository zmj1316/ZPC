`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:51:35 09/17/2015 
// Design Name: 
// Module Name:    CPU 
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
module CPU(input clk,rst,inout [31:0] BUS,
		   output reg Memread,output reg Memwrite, output reg [31:0] Addr
		  ,output reg [31:0] A
    );
reg [ 2: 0] stage;

wire [12:0] signal;



reg [31: 0] Regfile[31:0];
reg [31: 0] PC;

assign Regtest = Regfile[1];

wire [25:0] JUMP;
wire [5:0] OP;
wire [4:0] RS;
wire [4:0] RT;
wire [4:0] RD;
wire [4:0] shamt;
wire [5:0] func;
wire [15:0] imme0;

wire [31:0] imme;

reg [4:0] Dst;
reg [31:0] RA;
reg [31:0] RB;

reg [31:0] Alures;
// reg [31:0] A;
reg [31:0] B;

// reg [31:0] MDR;

wire [31:0] Memin;
reg [31:0] Memout;

reg [31:0] IR;



wire [31:0] shiftRes;
shifter S(B,shamt,shiftRes);

assign BUS = Memwrite?Memout:32'bz;
assign Memin = BUS;

assign OP = IR[31:26];
assign RS = IR[25:21];
assign RT = IR[20:16];
assign RD = IR[15:11];
assign JUMP = {6'b0,IR[25:0]};
assign shamt = IR[10:6];
assign func = IR[5:0];
assign imme0 = IR[15:0];
assign imme = {{16{imme0[15]}},imme0[15:0]};
Ctrl C(OP,signal);

initial begin
	A = 0;
	B = 0;
	Memread = 0;
	Memwrite = 0;
	stage = 0;
	PC = 0;
	IR = 0;
	Regfile[0] = 0;
	Regfile[1] = 233;
end
always @(posedge clk or posedge rst) begin
	if (rst) begin
		// reset
	end
	else begin
		Memread = 0;
		Memwrite = 0;
		case(stage)
			3'h0:begin

			end
			3'h1:begin				
				//IFS
				Addr = PC;
				PC = PC + 4;
				Memread = 1;
			end
			3'h2:begin
				IR = Memin;
				//IDS
				RA = Regfile[RS];
				RB = Regfile[RT];
				case(signal[8:7])
					2'b0: Dst = RT;
					2'b1: Dst = RD;
					2'b10: Dst = 5'h1F;
				endcase
			end
			3'h3:begin
				//EXS
				A = signal[11]? RA : PC;
				case(signal[10:9])
					2'h0: B = RB;
					2'h1: B = 4;
					2'h2: B = imme;
					2'h3: B = {imme[29:0],2'b00};
				endcase
				if (signal[12]) begin
					//ALU
					case(func)
						6'h20,6'h21: Alures = A + B;
						6'h22,6'h23: Alures = A - B;
						6'h24: Alures = A & B;
						6'h25: Alures = A | B;
						6'h26: Alures = A ^ B;
						6'h27: Alures = ~(A | B);
						6'h2A: Alures = ((A - B) & 32'h80000000 == 32'h80000000)? 1:0;
						6'h2B: Alures = (A < B)? 1:0;
						6'h0 : Alures = shiftRes;
					endcase
				end
				else begin
					Alures = A + B;
					case(OP)
						6'h0C: Alures = A & B;
						6'h0D: Alures = A | B;
						6'h0E: Alures = A ^ B;
						6'h0F: Alures = {B[15:0],16'b0};
					endcase
				end
				if (signal[0]) begin
					PC = signal[2]? Alures: {PC[31:28],JUMP,2'b00};
				end
				if (signal[1]) begin
					case(OP)
						6'h4: begin
							if (RA == RB) begin
								PC = Alures;
							end
						end
						6'h5: begin
							if (RA != RB) begin
								PC = Alures;
							end
						end
					endcase					
				end
			end
			3'h4:begin
				//MYS
				if (signal[4]) begin
					Addr = Alures;
					Memread = 1;					
					MDR = Memin;
				end
				if (signal[3]) begin
					Addr = Alures;
					Memout = RB;
					Memwrite = 1;
				end
			end
			3'h5:begin
				//WBS
				if (signal[5]) begin
					if (signal[6]) begin
						Regfile[Dst] = Memin;
					end
					else begin
						Regfile[Dst] = Alures;
					end
					Regfile[0] = 0;
				end
			end
			3'h6: begin

			end
		endcase
		stage = stage + 1;
	end
end
endmodule

module shifter(data,b,result);
parameter Nminus1 = 31; /* 32-bit shifter */
input [Nminus1:0] data;  /*compute parity of these bits */
input [4:0] b; /* amount to shift */
output [Nminus1:0] result; /* shift result */

assign result = data << b; 
endmodule
