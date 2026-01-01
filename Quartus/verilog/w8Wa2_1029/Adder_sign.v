module Adder_sign (X, Y, S_unsigned, S_signed);
	parameter n = 3;
	input [n-1:0] X, Y;
	output [n:0]S_unsigned, S_signed;
	
	assign S_unsigned = X + Y;
	assign S_signed = {{X[n-1], X} + {Y[n-1], Y}};

endmodule
