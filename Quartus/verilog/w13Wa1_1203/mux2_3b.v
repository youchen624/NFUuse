module mux2_3b(a, b, y, s, e);
	input [2:0] a, b;
	input s, e;
	output [2:0] y;

	assign y = (!e) ? 3'b0 : ((s) ? b : a );
		

endmodule
