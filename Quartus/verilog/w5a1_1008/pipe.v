module pipe(out, in, clk);
	output out;
	input in, clk;
	
	reg out;
	
	always @(in)
	begin
		out <= repeat(3) @(posedge clk) in;
	end

endmodule
