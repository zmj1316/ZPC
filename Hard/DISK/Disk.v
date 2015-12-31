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
module Disk(clk,TxD,RxD,BUS,Memread,Memwrite,Addrin,debug,PC,IR,Busy
	,Rstate,Tstate,TxD_busy,TxD_start
	// ,reading
    );

output reg [9:0] Rstate = 10'h0;
output reg [15:0] Tstate = 16'h0;
reg [7:0] Tsignal = 8'h0;
output reg TxD_start=0;

reg [15:0] BUSdata = 16'h0;

reg [7:0] TxD_data = 8'h0;
input clk;
output TxD;
input RxD;
inout [31:0]BUS;
input Memread;
input Memwrite;
input debug;
input [31:0] PC;
input [31:0] IR;
input [9:0] Addrin;
output wire TxD_busy;
output wire Busy;
reg anotherbusy = 0;
wire RxD_data_ready;
wire [7:0] RxD_data;
reg [7:0] Rdata;

reg [15:0] dsect = 16'h0;
// reg csect = 1'b1;

assign BUS = Memread?BUSdata:32'hz;
reg we = 0;
reg [8:0]addr;
wire [7:0]douta;
reg [7:0] datain;
reg reading = 0;
reg writing = 0;
assign Busy = reading|writing;

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
		10'h0: if(RxD_data_ready) Rstate=10'h1;
		10'h200: begin
			reading = 0;
			Rstate = 0;
		end
		default: if (RxD_data_ready) begin
			Rstate=Rstate+1;
			// reading = 1;
		end
	endcase
	if(RxD_data_ready)begin
		// Rdata = RxD_data ;
		reading = 1;
		we = 1;
		addr = Rstate[8:0] - 1;
		datain = RxD_data;
	end
	else if (Memwrite) begin
		if (Addrin[9]==1'b0) begin
			addr = Addrin;
			datain = BUS[7:0];
			we = 1;
		end
		else begin
			case(Addrin)
				10'h200: dsect = BUS[15:0]; // dsect
				10'h202: Tsignal = 1; // writesignal
			endcase
		end
	end
	else if (Memread) begin
		if (Addrin[9]==1'b0) begin
			addr = Addrin;
			BUSdata = douta;
		end
		else begin
			case(Addrin)
				10'h201: BUSdata ={15'h0,writing|reading};
				10'h202: Tsignal = 2; // readsignal
			endcase
		end
	end
	else if(debug&&!Busy) begin
		Tsignal = 3;
	end
	case(Tstate)
		16'h0: if (Tsignal!=0) begin
			writing = 1;
			TxD_data=Tsignal;
			if (Tsignal != 2'h3) begin
				Tstate=16'h2F1;
			end
			else if(Tsignal == 2'h3) begin
				Tstate = 16'h300;
			end
			TxD_start=1;
			anotherbusy = 1;
		end
		else begin
			writing=0;
			TxD_start = 0;
		end
		16'h2F1: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=dsect[7:0];
				Tstate=16'h2F2;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h2F2: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=dsect[15:8];
				Tstate=Tsignal[0]?16'h1:16'h2F3;
				anotherbusy=1;
				Tsignal = 0;
			end
			else begin
				anotherbusy=0;
				TxD_start=0;
			end		
		end
		16'h2F3: begin
			if (~TxD_busy&&~anotherbusy) begin
	   			reading = 1;
	   			Tsignal = 0;
	   			Tstate = 0;		
	   			TxD_start = 0;
			end
			else begin
				anotherbusy=0;
				TxD_start=0;
			end		
		end
		16'h300: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=PC[7:0];
				Tstate=16'h301;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h301: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=PC[15:8];
				Tstate=16'h302;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h302: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=PC[23:16];
				Tstate=16'h303;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h303: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=PC[31:24];
				Tstate=16'h304;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h304: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=IR[7:0];
				Tstate=16'h305;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h305: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=IR[15:8];
				Tstate=16'h306;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h306: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=IR[23:16];
				Tstate=16'h307;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h307: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=IR[31:24];
				Tstate=16'h308;
				anotherbusy = 1;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h308: begin
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=0;
				Tstate=16'h0;
				Tsignal=0;
			end
			else begin
				anotherbusy = 0;
				TxD_start=0;
			end
		end
		16'h200: begin
			addr = Tstate - 1;
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=douta;
				Tsignal = 0;
				Tstate=0;
				anotherbusy=1;
			end
			else begin
				anotherbusy=0;
				TxD_start=0;
			end
		end
		default: begin
			addr = Tstate - 1;
			if (~TxD_busy&&~anotherbusy) begin
				TxD_start=1;
				TxD_data=douta;
				Tstate=Tstate + 1;
				anotherbusy=1;
			end
			else begin
				anotherbusy=0;
				TxD_start=0;
			end		
		end

	endcase
end

endmodule
