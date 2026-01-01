`timescale 1ns/1ps
module TestBench2();
	reg clk;
	reg [5:0] X, Y;
	reg Cin;

	wire [5:0] S;
	wire Cout;
	wire [6:0] Result;

	integer i, j;

Adder_6 u0(.Cout(Cout), .S(S), .X(X), .Y(Y), .Cin(Cin));

assign Result = {Cout, S};

initial begin
	clk = 0;
	Cin = 0;
	X = 0;
	Y = 0;
end

always
	#10 clk = ~clk;

initial begin
	for(i =0; i < 64; i = i + 1)
	begin
		#1 X = i[5:0];
		repeat(4) @(posedge clk);
		for(j = 0; j < 64; j = j + 1)
		begin
			#1 Y =  j[5:0];
			@(posedge clk);
		end
	end
	$stop;
end

endmodule
