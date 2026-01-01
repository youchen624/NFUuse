module regtest1(c, a, b);
	input [1:0] a, b;
	output [2:0] c;
	reg [2:0] c;
	
	always @(a, b)
		c = a + b;

endmodule
