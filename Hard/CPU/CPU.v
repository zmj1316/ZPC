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
module CPU(clk,rst,BUS,
		   Memread,Memwrite,Addr,INTin,INTnum
		   // ,INT
		  // ,output reg [31:0] A,output reg [31:0]PC,output reg [31:0] IR,output reg [31:0] Alures
    );
input clk;// CPU clock
input rst;// reset signal
inout [31:0] BUS;// data BUS
output reg Memread;// memory read signal


output reg [1:0] Memwrite;// memory write
					  // 0:N/A 1:WORD 2:DMA 3:BYTE
output reg [31:0] Addr;// memory address
input INTin;
input [31:0] INTnum;
reg INT;
reg [ 2: 0] stage;// CPU stage counter

wire [13:0] signal;// control signal
/* signal define:
 * 13:Membyte? 12:ALUOP 11:SA 10-9:SB 8-7:RegDst 6:Mem2Reg 5:RegW 
 * 4:MemR 3:MemW 2:PC_S 1:PCWC 0:PCW
 */


reg [31: 0] Regfile[31:0];// Register file

// assign RegT = Regfile[1];

reg [31: 0] PC; //PC
// 14: EPC 13: Cause 12: STATUS
reg [31: 0] cReg[31:0];
wire [31:0] STATUS;
assign STATUS = cReg[12];


wire [25:0] Label;// JUMP address
wire [5:0] OP;// OP code
wire [4:0] RS;
wire [4:0] RT;
wire [4:0] RD;
wire [4:0] shamt;
wire [5:0] func;
wire [31:0] imme0;// imme in IR

wire [31:0] imme;// sign extend imme

reg [4:0] Dst;
reg [31:0] RA;
reg [31:0] RB;

reg [31:0] Alures;
reg [31:0] A;
reg [31:0] B;


wire [31:0] Memin;// data recieved
reg [31:0] Memout;// data to be write

reg [31:0] IR;// instruction



wire [31:0] RshiftRes;// shifted
wire [31:0] LshiftRes;// shifted

Rshifter RRS(B,shamt,RshiftRes);// srl
Lshifter LLS(B,shamt,LshiftRes);// sll

assign BUS = Memwrite?Memout:32'bz;// BUS adapter
assign Memin = BUS;// recieve data

//decode IR
assign OP = IR[31:26];
assign RS = IR[25:21];
assign RT = IR[20:16];
assign RD = IR[15:11];
assign Label = IR[25:0];
assign shamt = IR[10:6];
assign func = IR[5:0];
assign imme0 = {0,IR[15:0]};
assign imme = {{16{imme0[15]}},imme0[15:0]};

//control unit
Ctrl C(OP,signal);

//initialize regfile
integer i;
initial begin 
	for(i=0;i<32;i=i+1)
	begin 
		Regfile[i]=i;
		cReg[i] = 0;
	end
end

//initialize datapath
initial begin
	A = 0;
	B = 0;
	Memread = 0;
	Memwrite = 0;
	stage = 0;
	PC = 0;
	IR = 0;
end


// main loop
always @(posedge clk or posedge rst) begin
	if (rst) begin
		// reset
		A = 0;
		B = 0;
		Memread = 0;
		Memwrite = 0;
		stage = 0;
		PC = 0;
		IR = 0;
	end
	else begin
		// reset signals
		// stages
		case(stage)
			3'h0:begin
				//IFS
				//read instruction
				Memwrite = 0;
				Addr = PC;
				PC = PC + 2;
				Memread = 1;
				// Check INT from outside
				if (INTin == 1 && STATUS[0] == 0) begin
					INT = 1'b1;
					cReg[13] = INTnum;
				end
				if (INT == 1'b1) begin
					cReg[14] = PC - 2;
					PC = 32'h40C;
					INT = 1'b0;
					cReg[12] = cReg[12] | 32'h1;
					stage = -1;
				end
			end
			3'h1:begin			
				// deal with memory & control latency	
				IR = Memin;
				// interrupt here
			end
			3'h2:begin
				Memread = 0;

				//IDS
				RA = Regfile[RS];
				RB = Regfile[RT];
				case(signal[8:7]) //RegDst
					2'b0: Dst = RT;
					2'b1: Dst = RD;
					2'b10: Dst = 5'h1F;
				endcase
			end
			3'h3:begin
				//EXS
				A = signal[11]? RA : PC;//ALUsourseA
				case(signal[10:9])// ALUsourseB
					2'h0: B = RB;
					2'h1: B = 4;
					2'h2: B = imme;
					2'h3: B = {imme[30:0],1'b0};//imme << 1
				endcase

				if (signal[12]) begin// ALUOP
					//ALU
					case(func)
						6'h20,6'h21: Alures = A + B;
						6'h22,6'h23: Alures = A - B;
						6'h24: Alures = A & B;
						6'h25: Alures = A | B;
						6'h26: Alures = A ^ B;
						6'h27: Alures = ~(A | B);
						6'h2B: Alures = ((A - B) & 32'h80000000 == 32'h80000000)? 1:0;
						6'h2A: Alures = (A < B)? 1:0;
						6'h00 : Alures = B<<shamt;//sll
						6'h02 : Alures = B>>shamt;//srl
						6'h10: Alures = A * B;//mut
						6'h8: begin // JR
							PC = {RA[31:0]};
						end
						6'hC: begin // syscall
							cReg[13] = 8;
							INT = 1;
						end
					endcase
				end
				else begin
					Alures = A + B;
					//I-type
					case(OP)
						6'h03: Alures = PC; //jal
						6'h08: Alures = A + B;// addi
						6'h09: Alures = A + imme0;// addiu

						6'h0C: Alures = A & imme0;
						6'h0D: Alures = A | imme0;
						6'h0E: Alures = A ^ imme0;
						6'h0F: Alures = {imme[15:0],16'b0};//lui
						//6'h0A: Alures = (A < B)^(A[31]^B[31]) 1 : 0;//slti
						6'h0B: Alures = (A<imme0)?1:0;//sltiu
					endcase
				end
				// CO
				if( OP == 16) begin
					case (RS)
						5'h0: Alures = cReg[RD]; // mfc
						5'h4: cReg[RD] = RB; // mtc
						// 5'h4: cReg[RD] = Regfile[RT]; // mtc
						5'h10: begin // eret
							PC = cReg[14];
							cReg[12] = cReg[12] & 32'hFFFFFFFE;
						end
					endcase
				end
				//PC write
				if (signal[0]) begin
					// PC = signal[2]? Alures: {PC[31:28],JUMP,2'b00};
					PC = {PC[31:27],Label,1'b0};
				end
				//PC write cond
				if (signal[1]) begin
					case(OP)
						6'h4: begin//beq
							if (RA == RB) begin
								PC = Alures;
							end
						end
						6'h5: begin//bne
							if (RA != RB) begin
								PC = Alures;
							end
						end
					endcase
				end
			end
			3'h4:begin
				//MYS
				if (signal[4]) begin// Memread
					Addr = Alures;
					Memwrite = 0;
					Memread = 1;					
				end
				if (signal[3]) begin// Memwrite
					Addr = Alures;
					Memout = RB;
					Memread = 0;
					Memwrite = signal[13]?3:1;// BYTE?WORD
				end
			end
			3'h7:begin
				//WBS
				if (signal[5]) begin// Reg write
					if (signal[6]) begin// Mem to Reg
						Regfile[Dst] = signal[13]?{0,Memin[15:0]}:Memin;
					end
					else begin
						Regfile[Dst] = Alures;
					end
					Regfile[0] = 0;// $zero = 0
				end
			end
		endcase
		stage = stage + 1;
	end
end
endmodule

module Rshifter(data,b,result);
	parameter Nminus1 = 31; /* 32-bit shifter */
	input [Nminus1:0] data;  /*compute parity of these bits */
	input [4:0] b; /* amount to shift */
	output [Nminus1:0] result; /* shift result */

	assign result = data >> b; 
endmodule
module Lshifter(data,b,result);
	parameter Nminus1 = 31; /* 32-bit shifter */
	input [Nminus1:0] data;  /*compute parity of these bits */
	input [4:0] b; /* amount to shift */
	output [Nminus1:0] result; /* shift result */

	assign result = data << b; 
endmodule
