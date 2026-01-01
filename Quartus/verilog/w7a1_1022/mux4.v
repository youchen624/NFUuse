module mux4(y, a, b, c, d, s);
parameter n = 4;
	input [n-1:0] a, b, c, d;
	output [n-1:0] y;
	
	input [1:0] s;
	
	assign y = (s == 2'b00) ? a:
					(s == 2'b01) ? b:
					 (s == 2'b10) ? c: d;
endmodule
