module reg_blocking_4b3(y1, y2, y3, in, clk);
	output [3:0] y1, y2, y3;
	input clk;
	input [3:0] in;
	
	reg [3:0]y1, y2, y3;
	
	always @(posedge clk)
	begin
		y1 = in;
		y2 = y1;
		y3 = y2;
	end


endmodule
