create_clock -period 20 [get_ports CLOCK_50]
derive_clock_uncertainty
set_input_delay 0 -clock CLOCK_50 [all_inputs]
set_output_delay 0 -clock CLOCK_50 [all_outputs]