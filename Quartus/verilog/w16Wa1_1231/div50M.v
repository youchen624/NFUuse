module div50M(
	input clk, reset_n,
	output wire o
);

	integer i;
	
initial begin
	i = 0;
end

always @(posedge clk or negedge reset_n) begin
	if (!reset_n) i <= 0;
	else if (i == 50_000_000)
		i <= 0;
	else i <= i + 1;
end

assign o = (i == 50_000_000) ? 1 : 0;

endmodule
