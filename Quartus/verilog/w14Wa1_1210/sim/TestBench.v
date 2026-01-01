`timescale 1ns/1ps
module TestBench();
	reg clk, reset_n, cnt;

	wire [2:0] w1;
	wire [7:0] d_out;

	integer i;

counter_3 u1(.clk(clk), .reset_n(reset_n), .cnt(cnt), .count(w1));
decoder3_8 u2(.d(w1), .a(d_out));

initial begin
	clk = 0;
	cnt = 0;
	reset_n = 0;
end

always #10 clk = ~clk;

initial begin
	for (i = 0; i < 64; i = i + 1) begin
		repeat(2) @(posedge clk);
		if (i == 3)
			#1 reset_n = 0;
		if (i == 4)
			#1 cnt = 1;
		if (i == 8)
			#1 reset_n = 1;
	end
	$stop;
end

endmodule
