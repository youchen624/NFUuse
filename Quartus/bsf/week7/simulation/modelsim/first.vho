-- Copyright (C) 1991-2015 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus II License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 15.0.0 Build 145 04/22/2015 SJ Full Version"

-- DATE "04/08/2025 16:08:31"

-- 
-- Device: Altera 5CEBA4F23C7 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA_LNSIM;
LIBRARY CYCLONEV;
LIBRARY IEEE;
USE ALTERA_LNSIM.ALTERA_LNSIM_COMPONENTS.ALL;
USE CYCLONEV.CYCLONEV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	first4 IS
    PORT (
	D : OUT std_logic_vector(7 DOWNTO 0);
	A : IN std_logic_vector(2 DOWNTO 0);
	E : IN std_logic
	);
END first4;

-- Design Ports Information
-- D[7]	=>  Location: PIN_U1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D[6]	=>  Location: PIN_U2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D[5]	=>  Location: PIN_N1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D[4]	=>  Location: PIN_N2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D[3]	=>  Location: PIN_Y3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D[2]	=>  Location: PIN_W2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D[1]	=>  Location: PIN_AA1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D[0]	=>  Location: PIN_AA2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[0]	=>  Location: PIN_U13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[1]	=>  Location: PIN_V13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[2]	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- E	=>  Location: PIN_AB12,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF first4 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_D : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_A : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_E : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \A[1]~input_o\ : std_logic;
SIGNAL \E~input_o\ : std_logic;
SIGNAL \A[0]~input_o\ : std_logic;
SIGNAL \A[2]~input_o\ : std_logic;
SIGNAL \inst2|inst2|inst2~0_combout\ : std_logic;
SIGNAL \inst2|inst2|inst1~0_combout\ : std_logic;
SIGNAL \inst2|inst1|inst2~0_combout\ : std_logic;
SIGNAL \inst2|inst1|inst1~0_combout\ : std_logic;
SIGNAL \inst1|inst2|inst2~0_combout\ : std_logic;
SIGNAL \inst1|inst2|inst1~0_combout\ : std_logic;
SIGNAL \inst1|inst1|inst2~0_combout\ : std_logic;
SIGNAL \inst1|inst1|inst1~0_combout\ : std_logic;
SIGNAL \ALT_INV_E~input_o\ : std_logic;
SIGNAL \ALT_INV_A[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_A[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_A[0]~input_o\ : std_logic;

BEGIN

D <= ww_D;
ww_A <= A;
ww_E <= E;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_E~input_o\ <= NOT \E~input_o\;
\ALT_INV_A[2]~input_o\ <= NOT \A[2]~input_o\;
\ALT_INV_A[1]~input_o\ <= NOT \A[1]~input_o\;
\ALT_INV_A[0]~input_o\ <= NOT \A[0]~input_o\;

-- Location: IOOBUF_X0_Y19_N22
\D[7]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|inst2|inst2~0_combout\,
	devoe => ww_devoe,
	o => ww_D(7));

-- Location: IOOBUF_X0_Y19_N5
\D[6]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|inst2|inst1~0_combout\,
	devoe => ww_devoe,
	o => ww_D(6));

-- Location: IOOBUF_X0_Y19_N56
\D[5]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|inst1|inst2~0_combout\,
	devoe => ww_devoe,
	o => ww_D(5));

-- Location: IOOBUF_X0_Y19_N39
\D[4]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|inst1|inst1~0_combout\,
	devoe => ww_devoe,
	o => ww_D(4));

-- Location: IOOBUF_X0_Y18_N45
\D[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|inst2|inst2~0_combout\,
	devoe => ww_devoe,
	o => ww_D(3));

-- Location: IOOBUF_X0_Y18_N62
\D[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|inst2|inst1~0_combout\,
	devoe => ww_devoe,
	o => ww_D(2));

-- Location: IOOBUF_X0_Y18_N96
\D[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|inst1|inst2~0_combout\,
	devoe => ww_devoe,
	o => ww_D(1));

-- Location: IOOBUF_X0_Y18_N79
\D[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|inst1|inst1~0_combout\,
	devoe => ww_devoe,
	o => ww_D(0));

-- Location: IOIBUF_X33_Y0_N58
\A[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(1),
	o => \A[1]~input_o\);

-- Location: IOIBUF_X33_Y0_N75
\E~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_E,
	o => \E~input_o\);

-- Location: IOIBUF_X33_Y0_N41
\A[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(0),
	o => \A[0]~input_o\);

-- Location: IOIBUF_X34_Y0_N1
\A[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(2),
	o => \A[2]~input_o\);

-- Location: LABCELL_X1_Y18_N0
\inst2|inst2|inst2~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst2|inst2|inst2~0_combout\ = ( \A[0]~input_o\ & ( \A[2]~input_o\ & ( (\A[1]~input_o\ & \E~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000001100000011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_A[1]~input_o\,
	datac => \ALT_INV_E~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst2|inst2|inst2~0_combout\);

-- Location: LABCELL_X1_Y18_N9
\inst2|inst2|inst1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst2|inst2|inst1~0_combout\ = ( !\A[0]~input_o\ & ( \A[2]~input_o\ & ( (\E~input_o\ & \A[1]~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000101000001010000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_E~input_o\,
	datac => \ALT_INV_A[1]~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst2|inst2|inst1~0_combout\);

-- Location: LABCELL_X1_Y18_N12
\inst2|inst1|inst2~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst2|inst1|inst2~0_combout\ = ( \A[0]~input_o\ & ( \A[2]~input_o\ & ( (!\A[1]~input_o\ & \E~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000110000001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_A[1]~input_o\,
	datac => \ALT_INV_E~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst2|inst1|inst2~0_combout\);

-- Location: LABCELL_X1_Y18_N51
\inst2|inst1|inst1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst2|inst1|inst1~0_combout\ = ( !\A[0]~input_o\ & ( \A[2]~input_o\ & ( (\E~input_o\ & !\A[1]~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000001010000010100000000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_E~input_o\,
	datac => \ALT_INV_A[1]~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst2|inst1|inst1~0_combout\);

-- Location: LABCELL_X1_Y18_N54
\inst1|inst2|inst2~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst1|inst2|inst2~0_combout\ = ( \A[0]~input_o\ & ( !\A[2]~input_o\ & ( (\A[1]~input_o\ & \E~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000110000001100000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_A[1]~input_o\,
	datac => \ALT_INV_E~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst1|inst2|inst2~0_combout\);

-- Location: LABCELL_X1_Y18_N33
\inst1|inst2|inst1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst1|inst2|inst1~0_combout\ = ( !\A[0]~input_o\ & ( !\A[2]~input_o\ & ( (\E~input_o\ & \A[1]~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000010100000101000000000000000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_E~input_o\,
	datac => \ALT_INV_A[1]~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst1|inst2|inst1~0_combout\);

-- Location: LABCELL_X1_Y18_N36
\inst1|inst1|inst2~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst1|inst1|inst2~0_combout\ = ( \A[0]~input_o\ & ( !\A[2]~input_o\ & ( (!\A[1]~input_o\ & \E~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000011000000110000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_A[1]~input_o\,
	datac => \ALT_INV_E~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst1|inst1|inst2~0_combout\);

-- Location: LABCELL_X1_Y18_N45
\inst1|inst1|inst1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst1|inst1|inst1~0_combout\ = ( !\A[0]~input_o\ & ( !\A[2]~input_o\ & ( (\E~input_o\ & !\A[1]~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101000001010000000000000000000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_E~input_o\,
	datac => \ALT_INV_A[1]~input_o\,
	datae => \ALT_INV_A[0]~input_o\,
	dataf => \ALT_INV_A[2]~input_o\,
	combout => \inst1|inst1|inst1~0_combout\);

-- Location: LABCELL_X26_Y36_N0
\~QUARTUS_CREATED_GND~I\ : cyclonev_lcell_comb
-- Equation(s):

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
;
END structure;


