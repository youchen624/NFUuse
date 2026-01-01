module lab(A, B, Y, S, E);
	input [2:0] A, B;
	output [2:0] Y;
	input E, S;
	
mux2_3b u(.a(A), .b(B), .y(Y), .s(S), .e(E));

endmodule
