`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:40:00 09/23/2015 
// Design Name: 
// Module Name:    VGA 
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
module VGA(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync,clk_50mhz
,BUS,Memwrite,Addrin
// ,doutb,h_counter,clk_25mhz
);
output vga_red, vga_green, vga_blue, vga_hsync, vga_vsync;
input clk_50mhz;
// input rst;
inout [31:0]BUS;
input Memwrite;
input [31:0] Addrin;
assign BUS = 32'bz;

wire [10:0] h_counter;

wire [10:0] v_counter;
wire blank;
wire [2:0]topval;
wire clk_25mhz;
wire clk_24hz;

wire vga_red, vga_green, vga_blue;


clock_manager clocking(clk_25mhz, clk_6hz, clk_24hz, clk_50mhz, 0);

vga_controller_640_60 vga_controller(clk_25mhz, vga_hsync, vga_vsync, h_counter, v_counter, blank);

layer_compositor layering({vga_blue, vga_green, vga_red}, blank,topval);

reg we;
reg [11:0] addra;
reg [11:0] addrb;
reg [7:0] datain;
// reg [7:0] douta;
wire [7:0] doutb;
// output [7:0]doutb;
VM vm(
	.clka(clk_50mhz),
	.wea(we),
	.addra(Addrin[12:0]),
	.dina(BUS),
	// .douta(douta),
	.addrb(addrb),
	.clkb(clk_50mhz),
	.doutb(doutb)
	);

char c(doutb,h_counter[3:0],v_counter[3:0],topval[0],clk_50mhz);
initial begin
	we = 0;
	addra = 0;
	addrb = 0;
	datain = 0;
end
always @(posedge clk_25mhz) begin
	we = 0;
	begin
		addrb = {v_counter[8:4],h_counter[8:4]};
		// we = 1;
		if (Memwrite==1'b1) begin
			we = 1;
		end
	end
end


endmodule



module clock_manager(clk_25mhz, clk_6hz, clk_24hz, clk_50mhz, reset);
	output clk_25mhz;
	output clk_6hz;
	output clk_24hz;
	
	input clk_50mhz;
	input reset;
	
	wire  clk_6hz, clk_24hz;

	reg clk_25mhz = 0;
	
	 
	always @(posedge clk_50mhz) begin
		clk_25mhz <= ~clk_25mhz;
	end
	clock_divider slow_clk(clk_6hz, clk_24hz, clk_50mhz);

endmodule

module clock_divider(out, out8x, clk);
	output out, out8x;
	input clk;
	reg out, out8x;
	reg [20:0] counter;

	
	always @(posedge clk) begin
		if(counter == 21'b1_1111_1111_1111_1111_1111) out <= ~out;
		if(counter[17:0] == 18'b11_1111_1111_1111_1111) out8x <= ~out8x;
		counter <= counter + 1;
	end

endmodule
module vga_controller_640_60 (pixel_clk,HS,VS,hcounter,vcounter,blank);

	input pixel_clk;
	output HS, VS, blank;
	output [10:0] hcounter, vcounter;


	parameter HMAX = 800; // maxium value for the horizontal pixel counter
	parameter VMAX = 525; // maxium value for the vertical pixel counter
	parameter HLINES = 640; // total number of visible columns
	parameter HFP = 648; // value for the horizontal counter where front porch ends
	parameter HSP = 744; // value for the horizontal counter where the synch pulse ends
	parameter VLINES = 480; // total number of visible lines
	parameter VFP = 482; // value for the vertical counter where the frone proch ends
	parameter VSP = 484; // value for the vertical counter where the synch pulse ends
	parameter SPP = 0;



	wire video_enable;
	reg HS,VS,blank;
	reg [10:0] hcounter=0,vcounter=0;

	always@(posedge pixel_clk)begin
		blank <= ~video_enable; 
	end

	always@(posedge pixel_clk)begin
		if (hcounter == HMAX) hcounter <= 0;
		else hcounter <= hcounter + 1;
	end

	always@(posedge pixel_clk)begin
		if(hcounter == HMAX) begin
			if(vcounter == VMAX) vcounter <= 0;
			else vcounter <= vcounter + 1; 
		end
	end

	always@(posedge pixel_clk)begin
		if(hcounter >= HFP && hcounter < HSP) HS <= SPP;
		else HS <= ~SPP; 
	end

	always@(posedge pixel_clk)begin
		if(vcounter >= VFP && vcounter < VSP) VS <= SPP;
		else VS <= ~SPP; 
	end

	// assign video_enable = (hcounter < HLINES && vcounter < VLINES) ? 1'b1 : 1'b0;
	assign video_enable = (hcounter < 512 && vcounter < VLINES) ? 1'b1 : 1'b0;


endmodule



module layer_compositor(screenout, blank, topval);
	input [2:0] topval;
	input blank;
	output [2:0] screenout;
	reg [2:0] screenout;
	always@* begin
		if (blank)
			screenout = 3'b000;
		else if (topval != 3'b000)
			screenout = topval;
		
	end
endmodule