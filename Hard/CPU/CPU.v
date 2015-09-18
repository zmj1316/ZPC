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
module CPU(input clk,rst,input [31:0] Memin,output reg [31:0] Memout,
		   output reg Memread,output reg Memwrite, output reg [31:0] Addr
			,output [31:0] Regtest,output [31:0] PC,
			output [2:0]stage,output [12:0] signal,output [31:0] MDR
    );
reg [ 2: 0] stage;

wire [12:0] signal;



reg [31: 0] Regfile[31:0];
reg [31: 0] PC;

assign Regtest = Regfile[1];

reg [25:0] JUMP;
reg [5:0] OP;
reg [4:0] RS;
reg [4:0] RT;
reg [4:0] RD;
reg [4:0] shamt;
reg [5:0] func;
reg [31:0] imme;

reg [4:0] Dst;
reg [31:0] RA;
reg [31:0] RB;

reg [31:0] Alures;
reg [31:0] A;
reg [31:0] B;

reg [31:0] MDR;
Ctrl C(OP,signal);
initial begin
	Memread = 0;
	Memwrite = 0;
	stage = 0;
	PC = 0;
	Regfile[0] = 0;
	Regfile[1] = 0;
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
				//IFS
				Addr = PC;
				PC = PC + 4;
				Memread = 1;
				OP = (Memin >> 26) & 6'h3F;
				RS = (Memin >> 21) & 5'h1F;
				RT = (Memin >> 16) & 5'h1F;
				RD = (Memin >> 11) & 5'h1F;
				JUMP = Memin & 32'h3FFFFFFF;
				shamt = (Memin >> 6) & 5'h1F;
				func = Memin & 6'h3F;
				imme = Memin & 16'hFFFF;
			end
			3'h1:begin
				//IDS
				RA = Regfile[RS];
				RB = Regfile[RT];
				case(signal[8:7])
					2'b0: Dst = RT;
					2'b1: Dst = RD;
					2'b10: Dst = 5'h1F;
				endcase
				imme = {{16{imme[15]}},imme[15:0]};
			end
			3'h2:begin
				//EXS
				A = signal[11]? RA : PC;
				case(signal[10:9])
					2'h0: B = RB;
					2'h1: B = 4;
					2'h2: B = imme;
					2'h3: B = {imme[29:0],2'b00};
				endcase
				if (signal[12] == 1) begin
					//ALU
					case(func)
						6'h20,6'h21: Alures = A + B;
						6'h22,6'h23: Alures = A - B;
						6'h24: Alures = A & B;
						6'h25: Alures = A | B;
						6'h26: Alures = A ^ B;
						6'h27: Alures = ~(A | B);
					endcase
				end
				else begin
					Alures = A + B;
				end
				if (signal[0] == 1) begin
					PC = signal[2]? Alures: {PC[31:28],JUMP,2'b00};
				end
				if (signal[1] == 1) begin
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
			3'h3:begin
				//MYS
				if (signal[4] == 1) begin
					Addr = Alures;
					MDR = Memin;
					Memread = 1;					
				end
				if (signal[3] == 1) begin
					Addr = Alures;
					Memout = RB;
					Memwrite = 1;
				end
			end
			3'h4:begin
				if (signal[5] == 1) begin
					if (signal[6] == 1) begin
						Regfile[Dst] = MDR;
					end
					else begin
						Regfile[Dst] = Alures;
					end
					Regfile[0] = 0;
				end
			end
			3'h5: begin

			end
		endcase
		stage = stage + 1;
	end
end
endmodule
