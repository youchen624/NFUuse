module FD1(Q, D, CP);
	output Q;
	input D, CP;
	
	reg Q;
	
	always @(posedge CP)
	begin
		Q <= D;
	end


endmodule
