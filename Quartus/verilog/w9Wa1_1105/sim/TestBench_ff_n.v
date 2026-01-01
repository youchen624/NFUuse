`timescale 1ns/10ps
module TestBench_ff_n();
	reg clk;
	reg [3:0] in;
	wire [3:0] q, q_n;
	reg pre_n, clr_n, ce;

	integer i;

ff_n u1(.Q(q), .Q_n(q_n), .pre_n(pre_n), .clr_n(clr_n), .clk_n(clk), .D(in), .CE(ce));

initial begin
	clk = 0;
	in = 0;
	pre_n = 1;
	clr_n = 1;
	ce = 0;
end

initial begin
	forever #10 clk = ~clk;
end

initial begin
	for(i = 0; i < 100; i = i + 1)
	begin
		repeat(4) @(posedge clk);
		in = #3 i[3:0];
		if (i == 20)
			#1 pre_n = 0;
		if (i == 23)
			#1 pre_n = 1;
		if (i == 30)
			#1 clr_n = 0;
		if (i == 33)
			#1 clr_n = 1;
		if (i == 40)
			#1 ce = 1;
		if (i == 60)
			#1 ce = 0;
		if (i == 70)
			#1 ce = 1;
	end
end

endmodule
