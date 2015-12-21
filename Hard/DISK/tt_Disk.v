`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:55:17 12/03/2015 
// Design Name: 
// Module Name:    tt_Disk 
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
module tt_Disk(clk,TxD,RxD,signal,led,signal2
    );
input signal;
input clk;
output TxD;
input RxD;
output led;
input signal2;
reg Memwrite = 1'b0;
reg Memread = 1'b0;
reg [11:0] Addrin = 11'h0;
wire [31:0]BUS;
reg [31:0] writedata = 32'h0;
reg [8:0]state = 9'h0;
integer i = 0;
assign BUS = Memwrite?writedata:32'hz;
Disk dd(
	.clk(clk),
	.TxD(TxD),
	.RxD(RxD),
	.BUS(BUS),
	.Memread(Memread),
	.Memwrite(Memwrite),
	.Addrin(Addrin),
	.reading(led)
    );
always @(posedge clk) begin
	i = i + 1;
	if (i>200000000) begin
		i = 0;
	end
	Memwrite = 0;
	Memread = 0;
	case(state)
		9'h0:if(signal&& i >100000000)begin
				state = 9'h102;
				i = 0;
			end 
			else if(signal2&& i >100000000)begin
				state = 9'h100;
				i = 0;
			end

		9'h100: begin
			Addrin = 9'h100;
			writedata = 32'h11;
			Memwrite = 1'b1;
			state = state+1;
		end
		9'h101: begin
			Addrin = 9'h102;
			Memwrite = 1'b1;
			state = 0;
		end
		9'h102: begin
			Addrin = 9'h100;
			writedata = 32'h11;
			Memwrite = 1'b1;
			state = state+1;
		end
		9'h103: begin
			Memwrite = 1'b1;
			state=state+1;
		end
		9'h104: begin
			Addrin = 9'h102;
			Memread = 1'b1;
			state = state+1;
		end
		9'h105: begin
			Addrin = 9'h101;
			Memread = 1'b1;
			state = state+1;
		end
		9'h106: begin
			Memwrite = 1'b1;
			state = 0;
		end
		default: begin
			Memwrite=1;
			Addrin = state - 1;
			writedata = state - 1;
			state = state+1;
		end
	endcase
end
endmodule
