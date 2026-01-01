module regtest3(c, a, b);
	input [3:0] a, b;
	output [4:0] c;
	reg [4:0] c;
	
	always @(a, b)
		c = a + b;

endmodule
