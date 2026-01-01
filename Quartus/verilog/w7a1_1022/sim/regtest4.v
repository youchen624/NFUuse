module regtest4(c, a, b, clk);
	input [3:0] a, b;
	input clk;
	output [4:0] c;
	reg [4:0] c;

	always@(posedge clk)
		c = a + b;

endmodule
