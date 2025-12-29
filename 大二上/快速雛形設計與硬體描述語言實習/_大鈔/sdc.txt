create_clock -period 20 [get_ports CLK]
derive_clock_uncertainty
set_input_delay 0 -clock CLK [all_inputs]
set_output_delay 0 -clock CLK [all_outputs]
