`timescale 1ns/1ps
module TestBench2();

	reg clk, reset_n;
	wire o;

div50M u1(.clk(clk), .reset_n(reset_n), .o(o));

initial begin
	clk = 0;
	reset_n = 1;
end

always #10 clk = ~clk;

endmodule
