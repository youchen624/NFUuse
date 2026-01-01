module Adder_5(Cin, X, Y, S, Cout);

	output Cout;
	output [4:0] S;
	input Cin;
	input [4:0] X, Y;
	wire C_t;
	
	Adder_n #(3) S0(.Cout(C_t), .S(S[2:0]), .X(X[2:0]), .Y(Y[2:0]), .Cin(Cin));
	
	defparam S1.n = 2;
	Adder_n S1(.Cout(Cout), .S(S[4:3]), .X(X[4:3]), .Y(Y[4:3]), .Cin(C_t));

endmodule
