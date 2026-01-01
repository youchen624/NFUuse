module decoder3_8(
	input [2:0] d, //reg 
	output [7:0] a
);

assign a = (8'b1 << d);

endmodule
