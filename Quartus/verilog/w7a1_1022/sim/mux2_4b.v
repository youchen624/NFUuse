module mux2_4b(y, a, b, s);
// parameter n = 2;
	input [3:0] a, b;
	output [3:0] y;
	reg [3:0] e;
	
	input s;
	
	assign e = ~4'b0;
	assign y = (s == 1) ? (b & e) : (a & e);
endmodule