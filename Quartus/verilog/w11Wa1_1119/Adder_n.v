module Adder_n(Cout, S, X, Y, Cin);
parameter n = 4;

	output Cout;
	output [n-1:0] S;
	input Cin;
	input [n-1:0] X, Y;
	
	assign {Cout, S} = {1'b0, X} + {1'b0, Y} + Cin;//{n{1'b0}, Cin};

endmodule
