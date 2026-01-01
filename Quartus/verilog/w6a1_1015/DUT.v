module DUT(s, OUT);
	input  [9:0] s;
	output [4:0] OUT;
	
	integer k;
	
	reg 	 [4:0] Count;
	
	always @(*)
	begin
		Count = 0;
		for(k = 0;k < 10; k= k + 1)
			if(s[k])
				Count = Count + 1;
	end
	assign OUT = Count;
endmodule
