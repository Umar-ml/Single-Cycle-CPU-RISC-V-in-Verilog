module top_module(
	input [31:0] instruction,
	input [31:0] reg_input,
	output [31:0] result
);
	wire [31:0] imm;
	wire priority_out, mux_select;
	immediate_generator imm_gen(
		.instruction(instruction),
		.imm(imm),
		.priority_out(priority_out)
	);
	priority_encoder encoder(
		.enable(priority_out),
		.mux_select(mux_select)
	);
	mux_2to1 mux(
		.imm_input(imm),
		.reg_input(reg_input),
		.select(mux_select),
		.out(result)
	);
endmodule	
		
