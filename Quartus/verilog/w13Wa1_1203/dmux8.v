module dmux8(d, y, s, e);
	input d, e;
	input [2:0] s;
	output [7:0] y;
	
	assign y = (e & d) ? (8'b1 << s) : 8'b0;

endmodule
