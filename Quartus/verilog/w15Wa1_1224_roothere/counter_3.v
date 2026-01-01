module counter_3(
	input clk, reset_n, cnt,
	output reg [2:0] count
);

	always @(posedge clk or negedge reset_n) begin
		if (!reset_n) count <= 0;
		else if (cnt) count <= count + 1;
//		else count <= count - 1;
	end

endmodule
