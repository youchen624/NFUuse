module regtest2(c, a, b, clk);
	input [1:0] a, b;
	input clk;
	output [2:0] c;
	reg [2:0] c;

	always@(posedge clk)
		c = a + b;

endmodule
