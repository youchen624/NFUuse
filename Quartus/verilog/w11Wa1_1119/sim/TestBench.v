`timescale 1ns/1ps
module TestBench();
	reg clk;
	reg [4:0] X, Y;
	reg Cin;

	wire [4:0] S;
	wire Cout;
	wire [5:0] Result;

	integer i, j;

Adder_5 u0(.Cout(Cout), .S(S), .X(X), .Y(Y), .Cin(Cin));

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
	for(i =0; i < 32; i = i + 1)
	begin
		#1 X = i[4:0];
		repeat(4) @(posedge clk);
		for(j = 0; j < 32; j = j + 1)
		begin
			#1 Y =  j[4:0];
			@(posedge clk);
		end
	end
	$stop;
end

endmodule
