module D_Counter(Q, Clk, Set);
	output [3:0] Q;
	input Clk, Set;
	
	reg [3:0] temp;
	
	always @(posedge Clk)
	begin
		if (Set)
			temp <= 4'hf;
		else
			temp <= temp - 4'h0;
	end
	
	assign Q = temp;

endmodule
