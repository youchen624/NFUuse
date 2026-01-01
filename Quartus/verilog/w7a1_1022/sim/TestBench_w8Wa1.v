`timescale 1ns/100ps
module TestBench_w8Wa1();
parameter n = 4;
	reg clk;
	reg clk2;
	reg [n-1:0] A, B;
	reg S;

	wire [n-1:0] Y;
	integer i, j, k;

mux2_4b u1(.y(Y), .a(A), .b(B), .s(S));

initial begin
	clk = 0;
	clk2 = 0;
	S = 0;
end

initial begin
	forever #10 clk = ~clk;
end


initial begin
	forever #4 clk2 = ~clk2;
end


initial begin
	for(i=0; i<4; i=i+1)
	begin
		A=i[3:0];
		@ (posedge clk);
	end
end

initial begin
	for(j=3; j>=0; j=j-1)
	begin
		B=j[3:0];
		@ (posedge clk);
	end
end

initial begin
	for(k=0; k < 100; k = k +1)
	begin
		S = ~S;
		@ (posedge clk2);
	end
end

endmodule
