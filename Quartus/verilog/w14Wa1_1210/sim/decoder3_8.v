module decoder3_8(d, y, e);
	output [7:0] y;
	input  [2:0] d;
	input  e;
assign y = (8'b1 << d) & {8{e}};

endmodule
