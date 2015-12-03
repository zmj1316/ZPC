`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:06:47 12/03/2015 
// Design Name: 
// Module Name:    Disk 
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
module Disk(clk,TxD,RxD,BUS,Memread,Memwrite,Addrin
    );

reg [8:0] Rstate = 0;
reg [9:0] Tstate = 0;
reg [1:0] Tsignal = 0;
reg TxD_start=0;

reg [15:0] BUSdata = 0;

reg [7:0] TxD_data = 8'h0;
input clk;
output TxD;
input RxD;
inout [31:0]BUS;
wire TxD_busy;
wire RxD_data_ready;
wire [7:0] RxD_data;
reg [7:0] Rdata;

reg [15:0] dsect;
reg [15:0] csect = 16'hFFFF;

assign BUS = Memread?BUSdata:32'hz;
reg we = 0;
reg [8:0]addr;
wire [7:0]douta;
reg [7:0] datain;
DB ram(
	.clka(clk),
	.wea(we),
	.addra(addr),
	.dina(datain),
	.douta(douta)
);


async_transmitter at(
	.clk(clk),
	.TxD_start(TxD_start),
	.TxD_data(TxD_data),
	.TxD(TxD),
	.TxD_busy(TxD_busy)
	);
async_receiver ar(
	.clk(clk),
	.RxD(RxD),
	.RxD_data_ready(RxD_data_ready),
	.RxD_data(RxD_data)
	);
always @(posedge clk) begin
	we = 0;
	
	case (Rstate)
		9'h0: if(RxD_data_ready) Rstate<=9'h1;
		default: if (RxD_data_ready) begin
			Rstate<=Rstate+1;
		end
	endcase
	if(RxD_data_ready)begin
		// Rdata = RxD_data ;
		we = 1;
		addr = Rstate - 1;
		datain = Rdata;
	end 
	else if (Memwrite) begin
		if (Addrin<256) begin
			addr = Addrin;
			datain = BUS[7:0];
			we = 1;
		end
		else begin
			case(Addrin)
				9'h100: dsect = BUS[15:0]; // dsect
				9'h102: Tsignal = 1; // writesignal
			endcase
		end
	end
	else if (Memread) begin
		if (Addrin<256) begin
			addr = Addrin;
			BUSdata = douta;
		end
		else begin
			case(Addrin)
				9'h101: BUSdata = csect;
				9'h102: Tsignal = 2; // readsignal
			endcase
		end
	end
	case(Tstate)
		10'h0: if (Tsignal!=0) begin
			Tstate<=10'h201;
			TxD_start=0;
		end
		10'h201: begin
			if (~TxD_busy) begin
				TxD_start=1;
				TxD_data=dsect[7:0];
				Tstate<=10'h202;
			end
			else begin
				TxD_start=0;
			end
		end
		10'h202: begin
			if (~TxD_busy) begin
				TxD_start=1;
				TxD_data=dsect[15:8];
				Tstate<=Tsignal[0]?10'h1:10'h203;
			end
			else begin
				TxD_start=0;
			end		
		end
		10'h203: begin
			Tsignal = 0;
			Tstate <= 0;			
		end
		10'h200: begin
			addr = Tstate - 1;
			if (~TxD_busy) begin
				TxD_start=1;
				TxD_data=douta;
				Tstate<=0;
			end
			else begin
				TxD_start=0;
			end
		end
		default: begin
			addr = Tstate - 1;
			if (~TxD_busy) begin
				TxD_start=1;
				TxD_data=douta;
				Tstate<=Tstate + 1;
			end
			else begin
				TxD_start=0;
			end		
		end

	endcase
end

endmodule
