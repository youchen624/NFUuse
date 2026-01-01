module pipe2(out, in, clk);
	output out;
	input in, clk;
	
	reg out;
	reg one, two;
	
	always @(posedge clk)
	begin
		out <= two;
		two <= one;
		one <= in;
	end

endmodule
