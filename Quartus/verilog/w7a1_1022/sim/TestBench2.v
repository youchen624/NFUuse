`timescale 1ns/100ps
module TestBench();
parameter n = 4;
	reg clk;
	reg clk2;
	reg [n-1:0] A, B, C, D;
	reg [1:0] S;

	wire [n-1:0] Y;
	integer i, j, k, m, q;

mux4 u1(.y(Y), .a(A), .b(B), .c(C), .d(D), .s(S));

initial begin
	clk = 0;
	clk2 = 0;
end

initial begin
	forever #10 clk = ~clk;
end

initial begin
	forever #0.3 clk2 = ~clk2;
end

initial begin
	for(i=0; i<100; i=i+1)
	begin
		A=i[3:0];
		@ (posedge clk2);
	end
end

initial begin
	for(j=0; j<100; j=j+1)
	begin
		B=j[3:0];
		repeat(2) @ (posedge clk2);
	end
end

initial begin
	for(k=0; k<100; k=k+1)
	begin
		C=k[3:0];
		repeat(3) @ (posedge clk2);
	end
end

initial begin
	for(m=0; m<100; m=m+1)
	begin
		D=m[3:0];
		@ (posedge clk2);
	end
end

initial begin
	for(q=0; q<100; q=q+1)
	begin
		S=q[1:0];
		@ (posedge clk);
	end
end

endmodule
