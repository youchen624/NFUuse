module pipes(out, in, clk);
	output out;
	input in, clk;
	
	wire one, two;
	
	FD1 u1(.Q(one), .D(in), .CP(clk));
	FD1 u2(.Q(two), .D(one), .CP(clk));
	FD1 u3(.Q(out), .D(two), .CP(clk));

endmodule
