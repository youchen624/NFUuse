`timescale 1ns/1ns
module TestBentch2();
	reg E, D;
	reg [2:0] S;
	wire [7:0] Y;

	reg CLK;

	integer i;

dmux8 u1(.d(D), .y(Y), .s(S), .e(E));

initial begin
	CLK = 0;
	E = 0;
	i = 0;
	D = 0;
	forever #0.77 D = ~D;
end

always #10 CLK = ~CLK;

initial begin
	for (i = 0; i < 16; i = i + 1)
	begin
		repeat(3) @(posedge CLK);
		S = i[2:0];
		if (i == 5) E = 1;
	end
end

endmodule
