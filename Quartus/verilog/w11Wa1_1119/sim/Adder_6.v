module Adder_6(Cin, X, Y, S, Cout);

	output Cout;
	output [5:0] S;
	input Cin;
	input [5:0] X, Y;
	wire C_t0, C_t1;
	
	defparam S0.n = 1;
	defparam S1.n = 2;
	defparam S2.n = 3;
	Adder_n S0(.Cout(C_t0), .S(S[0:0]), .X(X[0:0]), .Y(Y[0:0]), .Cin(Cin));//#(3) 
	Adder_n S1(.Cout(C_t1), .S(S[2:1]), .X(X[2:1]), .Y(Y[2:1]), .Cin(C_t0)); 
	Adder_n S2(.Cout(Cout), .S(S[5:3]), .X(X[5:3]), .Y(Y[5:3]), .Cin(C_t1));

endmodule
