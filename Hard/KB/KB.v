module ps2scan(input clk,		
					input rst_n,	
					input ps2k_clk,	
					input ps2k_data,		
					output[7:0] ps2_byte,	
					output ps2_state		
					);

//------------------------------------------
reg ps2k_clk_r0,ps2k_clk_r1,ps2k_clk_r2;	

wire neg_ps2k_clk;	
reg[7:0] ps2_byte_r;		
reg[7:0] temp_data;			
reg[3:0] num;				
initial begin
	ps2k_clk_r0 <= 1'b0;
	ps2k_clk_r1 <= 1'b0;
	ps2k_clk_r2 <= 1'b0;
	num <= 4'd0;
	temp_data <= 8'd0;
end
always @ (posedge clk or negedge rst_n) begin
	if(!rst_n) begin
			
		end
	else begin								
			ps2k_clk_r0 <= ps2k_clk;
			ps2k_clk_r1 <= ps2k_clk_r0;
			ps2k_clk_r2 <= ps2k_clk_r1;
		end
end

assign neg_ps2k_clk = ~ps2k_clk_r1 & ps2k_clk_r2;	



always @ (posedge clk or negedge rst_n) begin
	if(!rst_n) begin

		end
	else if(neg_ps2k_clk) begin	
			case (num)
				4'd0:	num <= num+1'b1;
				4'd1:	begin
							num <= num+1'b1;
							temp_data[0] <= ps2k_data;	//bit0
						end
				4'd2:	begin
							num <= num+1'b1;
							temp_data[1] <= ps2k_data;	//bit1
						end
				4'd3:	begin
							num <= num+1'b1;
							temp_data[2] <= ps2k_data;	//bit2
						end
				4'd4:	begin
							num <= num+1'b1;
							temp_data[3] <= ps2k_data;	//bit3
						end
				4'd5:	begin
							num <= num+1'b1;
							temp_data[4] <= ps2k_data;	//bit4
						end
				4'd6:	begin
							num <= num+1'b1;
							temp_data[5] <= ps2k_data;	//bit5
						end
				4'd7:	begin
							num <= num+1'b1;
							temp_data[6] <= ps2k_data;	//bit6
						end
				4'd8:	begin
							num <= num+1'b1;
							temp_data[7] <= ps2k_data;	//bit7
						end
				4'd9:	begin
							num <= num+1'b1;	
						end
				4'd10: begin
							num <= 4'd0;	
						end
				default: ;
				endcase
		end	
end

reg key_f0;		
reg ps2_state_r;	

always @ (posedge clk or negedge rst_n) begin	
	if(!rst_n) begin
			key_f0 <= 1'b0;
			ps2_state_r <= 1'b0;
			ps2_byte_r <= temp_data;
		end
	else if(num==4'd10) begin	
			if(temp_data == 8'hf0) 
				key_f0 <= 1'b1;
			else begin
					if(!key_f0) begin	
							ps2_state_r <= 1'b1;
							ps2_byte_r <= temp_data;	
						end
					else begin
							ps2_state_r <= 1'b0;
							key_f0 <= 1'b0;
						end
				end
		end
end

reg[7:0] ps2_asci;

always @ (ps2_byte_r) begin
	case (ps2_byte_r)
		8'h15: ps2_asci <= 8'h51;	//Q
		8'h1d: ps2_asci <= 8'h57;	//W
		8'h24: ps2_asci <= 8'h45;	//E
		8'h2d: ps2_asci <= 8'h52;	//R
		8'h2c: ps2_asci <= 8'h54;	//T
		8'h35: ps2_asci <= 8'h59;	//Y
		8'h3c: ps2_asci <= 8'h55;	//U
		8'h43: ps2_asci <= 8'h49;	//I
		8'h44: ps2_asci <= 8'h4f;	//O
		8'h4d: ps2_asci <= 8'h50;	//P				  	
		8'h1c: ps2_asci <= 8'h41;	//A
		8'h1b: ps2_asci <= 8'h53;	//S
		8'h23: ps2_asci <= 8'h44;	//D
		8'h2b: ps2_asci <= 8'h46;	//F
		8'h34: ps2_asci <= 8'h47;	//G
		8'h33: ps2_asci <= 8'h48;	//H
		8'h3b: ps2_asci <= 8'h4a;	//J
		8'h42: ps2_asci <= 8'h4b;	//K
		8'h4b: ps2_asci <= 8'h4c;	//L
		8'h1a: ps2_asci <= 8'h5a;	//Z
		8'h22: ps2_asci <= 8'h58;	//X
		8'h21: ps2_asci <= 8'h43;	//C
		8'h2a: ps2_asci <= 8'h56;	//V
		8'h32: ps2_asci <= 8'h42;	//B
		8'h31: ps2_asci <= 8'h4e;	//N
		8'h3a: ps2_asci <= 8'h4d;	//M
		default: ;
		endcase
end

assign ps2_byte = ps2_asci;	 
assign ps2_state = ps2_state_r;

endmodule