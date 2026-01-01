module D_Counter_7(Q, Clk, Set);
	output [6:0] Q;
	input Clk, Set;
	
	reg [6:0] temp;
	
	always @(posedge Clk)
	begin
		if (Set)
			temp <= 7'b1111111;
		else
			temp <= temp - 7'h1;
	end
	
	assign Q = temp;

endmodule
