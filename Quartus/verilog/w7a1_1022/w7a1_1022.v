module mux4(y, a, b, c, d);
parameter n = 4;
	input [n-1:0] a, b, c, d;
	output [n-1:0] y;
endmodule
