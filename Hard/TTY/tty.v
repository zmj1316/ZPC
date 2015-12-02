`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:24:39 11/15/2015 
// Design Name: 
// Module Name:    tty 
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
module tty(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,clk_50mhz,ps2_clk,ps2_data,
			BUS,write,read,keypress
			,TxD,RxD
			// ,writeback,readback
    );
output vga_red, vga_green, vga_blue, vga_hsync, vga_vsync;
input clk_50mhz;
inout ps2_clk,ps2_data;
inout [31:0]BUS;
input read ,write;
output reg keypress;

reg [7:0] readdata = 8'h41;
reg VMwrite;
wire ttywrite;
wire [7:0] ascii;
wire released;
reg [7:0] ascdata;
reg TxD_start=0;
reg [7:0] TxD_data = 0;
output TxD;
input RxD;
wire TxD_busy;
wire RxD_data_ready;
wire [7:0] RxD_data;

assign BUS = read?{0,readdata}:32'bz;

reg [7:0] writedata;
VGA vga(
	.vga_red(vga_red),
	.vga_green(vga_green),
	.vga_blue(vga_blue),
	.vga_hsync(vga_hsync),
	.vga_vsync(vga_vsync),
	.clk_50mhz(clk_50mhz),
	.BUS(writedata),
	.Memwrite(VMwrite),
	.ttywrite(ttywrite)
	// .Addrin({0,Addr[3:0]})
	);

ps2_keyboard_interface kb(
	.clk(clk_50mhz),
	.ps2_clk(ps2_clk),
	.ps2_data(ps2_data),
	.rx_ascii(ascii),
	.rx_released(released)
	);
async_transmitter at(
	.clk(clk_50mhz),
	.TxD_start(released),
	.TxD_data(TxD_data),
	.TxD(TxD),
	.TxD_busy(TxD_busy)
	);
async_receiver ar(
	.clk(clk_50mhz),
	.RxD(RxD),
	.RxD_data_ready(RxD_data_ready),
	.RxD_data(RxD_data)
	);
// always @(posedge released) begin
// 	ascdata = ascii;
// end


always @(posedge clk_50mhz) begin

	TxD_start = 0;
	if (write == 1) begin
		VMwrite = 1;
		writedata = BUS;
	end
	else begin
		VMwrite = 0;
		if (RxD_data_ready) begin
			VMwrite = 1;
			writedata = RxD_data;
		end
		if (released == 1) begin
			readdata = ascii;
			keypress = 1;
			VMwrite = 1;
			writedata = ascii;
			// TxD_start = 1;
			TxD_data = ascii;
		end
		if (released == 0) begin
			// readdata = 8'hFF;
			keypress = 0;
		end
		// if (keypress == 1 && read == 1) begin
		// 	// readdata = 8'hff;
			
		// end
	end
end
endmodule
