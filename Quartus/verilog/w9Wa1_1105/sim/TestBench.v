`timescale 1ns/10ps
module TestBench();
	reg clk;
	reg [3:0] in;
	wire [3:0] y1_bk, y2_bk, y1_nbk, y2_nbk;
	wire [3:0] y3_bk, y3_nbk;

	integer i;

// reg_blocking u1(.y1(y1_bk), .y2(y2_bk), .in(in), .clk(clk));
// reg_noblocking u2(.y1(y1_nbk), .y2(y2_nbk), .in(in), .clk(clk));
reg_blocking_4b3 u1(.y1(y1_bk), .y2(y2_bk), .y3(y3_bk), .in(in), .clk(clk));
reg_noblocking_4b3 u2(.y1(y1_nbk), .y2(y2_nbk), .y3(y3_nbk), .in(in), .clk(clk));

initial begin
	clk = 0;
	in = 0;
end

initial begin
	forever #10 clk = ~clk;
end

initial begin
	for(i = 0; i < 10000; i = i + 1)
	begin
		repeat(4) @(posedge clk);
		in = #3 i[3:0];
	end
	$stop;
end

endmodule

