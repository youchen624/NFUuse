module pencoder8_3(
	output reg [2:0] y,
	output reg v,
	input wire [7:0] d
);


//	output reg [2:0] y;
//	output v;

//	input [7:0] d;

//	reg [2:0] y;
//	reg [7:0]d;
	integer i;
	// 8'b0000_000x // x = dont care

	always @(*) begin
		v = 1'b0;
		y = 8'b0;
		for (i = 0; i < 8; i = i + 1) begin
			if (d[i]) begin
				y = i;
				v = 1'b1;
			end
		end
	end

endmodule
