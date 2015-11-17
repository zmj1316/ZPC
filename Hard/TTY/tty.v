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
			BUS,write,read
			// ,writeback,readback
    );

inout [31:0]BUS;

reg [7:0] readdata;
reg VMwrite;
wire ttywrite;
wire [7:0] ascii;
wire released;
reg [7:0] ascdata;
assign BUS = read?readdata:32'bz;

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

// always @(posedge released) begin
// 	ascdata = ascii;
// end


always @(posedge clk_50mhz) begin
	VMwrite = 0;
	if (write == 1 && ttywrite == 0) begin
		VMwrite = 1;
	end
	if (released == 1) begin
		readdata = ascii;
		VMwrite = 1;
		writedata = ascii;
	end
	if (released == 0) begin
		readdata = 8'hFF;
	end
end
endmodule
