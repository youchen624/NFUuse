`timescale 1ns/100ps
module TestBench();
	reg clk;
	wire [4:0] out;
	integer i;

DUT	u1(.s(i[9:0]), .OUT(out));

initial begin
	clk = 0;
end

initial begin
	forever #10 clk = ~clk;
end

initial begin
	for(i = 0; i < 1024; i = i + 1)
		@(posedge clk);
end

endmodule
