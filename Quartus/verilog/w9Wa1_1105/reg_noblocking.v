module reg_noblocking(y1, y2, in, clk);
	output [3:0] y1, y2;
	input clk;
	input [3:0] in;
	
	reg [3:0]y1, y2;
	
	always @(posedge clk)
	begin
		y1 <= in;
		y2 <= y1;
	end


endmodule
