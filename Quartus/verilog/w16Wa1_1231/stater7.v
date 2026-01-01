module stater7(
	input next, reset, pause,
	output [2:0] state_out,
	output reg [3:0] id
);

	reg [2:0] state;
	
initial begin
	state = 0;
end

always @(posedge next or negedge reset) begin
	if (!reset) state <= 0;
	else begin
		if(pause) begin
			case(state)
					1: state = 2;
					3: state = 4;
					5, 6: state = 0;
			endcase
		end else begin
			state = state + 1;
			if (state >= 7) state = 0;
		end
	end
end

assign state_out = state;

always @* begin
	case (state)
		0, 4: id = 4'd1;
		2: 	id = 4'd3;
		default: begin
			id = 4'd15;
		end
	endcase
	
end


endmodule
