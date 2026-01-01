module lab(
	input clk, sw0, key0,
	output [6:0] seg
);

wire d;
wire nope;
wire [3:0] wbcd;

div50M u_div(.clk(clk), .reset_n(key0), .o(d));
bcd_seg u_bcd(.bcd(wbcd), .seg(seg));
stater7 u_st(.next(d), .pause(sw0), .reset(key0), .state_out(nope), .id(wbcd));

endmodule
