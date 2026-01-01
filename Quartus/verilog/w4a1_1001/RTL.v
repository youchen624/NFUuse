module RTL (A, B, C, D, Out);
	input A, B, C, D;
	output Out;
	reg Out;
	always @ (A or B or C or D)
	begin
		if(A & B & ~D)
			Out = C;
		else if (A & D & ~C)
			Out = B;
		else
			Out = 0;
	end

endmodule
