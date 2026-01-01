module lab(
	input clk, key0,
	output [7:0] led
);
	wire o50M;
	wire [2:0] c;
	
div50M u50M(.clk(clk), .reset_n(key0), .o(o50M));
counter_3 u0(.clk(clk), .reset_n(key0), .cnt(o50M), .count(c));
decoder3_8 u1(.d(c), .a(led));

endmodule
