module lab(
//	input  dm_d, //dm_e__de_e,//dm_e, de_e,
//	input  [1:0] m_s,
//	input  [2:0] dm_s__de_d,
	//input  [2:0] dm_s, de_d,
//	input  [7:0] pe_d,
	input key3,
	input [9:0] sw_b10,
	output [7:0] m_y
);

	wire pe_v;
	wire [2:0] pe_y;
	wire [7:0] m_0, m_1, m_2, m_3;

	assign m_1 = {pe_v, 3'b0, pe_y};
	assign m_3 = 8'b0;	// GND_b8

mux4_b8 		u_m	(.y(m_y), 	.a(m_0), 	.b(m_1), 	.c(m_2), 	.d(m_3), .s(sw_b10[9:8]));
dmux8_e 		u_dm	(.y(m_0), 	.d(sw_b10[3]), 	.e(key3), 	.s(sw_b10[2:0]));
pencoder8_3 u_pe	(.y(pe_y), 	.v(pe_v), 	.d(sw_b10[7:0]));
decoder3_8 	u_de	(.d(sw_b10[2:0]), 	.y(m_2), 	.e(key3));

endmodule
