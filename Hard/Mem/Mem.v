`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:25:01 09/20/2015 
// Design Name: 
// Module Name:    Mem 
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
module Mem(clk,BUS,Memread,Memwrite,Addrin,rst
    );
input clk;// memory clock
inout [31:0] BUS;// data BUS
input Memread;
input [1:0] Memwrite;
input [11:0] Addrin;
input rst;
//clock divider
reg st;
initial st = 0;
always @(posedge clk or posedge rst) begin
	if (rst) begin
		// reset
		st = 0;
	end
	else begin
		st = ~st;
	end
end

wire [31:0] douta;

reg [31:0] datain;// data to be writeen
reg [11:0] addr;
reg [63:0] tmp;
reg [31:0] Memout;// data to be sent
reg we;// write enable

assign BUS = Memread?Memout:32'bz;

BB ram(
	.clka(clk),
	.wea(we),
	.addra(addr),
	.dina(datain),
	.douta(douta)
);

always @(posedge clk or posedge rst) begin
	if (rst) begin
		// reset
		we = 0;
	end
	else begin
		we = 0;
		case(st)
			0: begin
				addr = Addrin;
				tmp[31:0] = douta;
			end
			1: begin
				addr = Addrin + 1;
				tmp[63:32] = douta;
			end
		endcase
		case(Memwrite)
			1: begin
				case(Addrin[1:0])
					0: datain = st? tmp[63:32]:BUS;
					1: datain = st? {tmp[63:40],BUS[31:24]}:{BUS[23:0],tmp[7:0]};
					2: datain = st? {tmp[63:48],BUS[31:16]}:{BUS[15:0],tmp[15:0]};
					3: datain = st? {tmp[63:56],BUS[31:8]}:{BUS[7:0],tmp[23:0]};
				endcase
				we = 1;
			end
			3: begin
				case(Addrin[1:0])
					0: datain = st? tmp[63:32]:{tmp[31:8],BUS[7:0]};
					1: datain = st? tmp[63:32]:{tmp[31:16],BUS[7:0],tmp[7:0]};
					2: datain = st? tmp[63:32]:{tmp[31:24],BUS[7:0],tmp[15:0]};
					3: datain = st? tmp[63:32]:{BUS[7:0],BUS[7:0],tmp[23:0]};
				endcase
				we = 1;
			end
		endcase
	end
end
always @(*) begin
	case(Addrin[1:0])
		0: Memout = tmp[31: 0];
		1: Memout = tmp[39: 8];
		2: Memout = tmp[47:16];
		3: Memout = tmp[55:24];
	endcase
end
endmodule
