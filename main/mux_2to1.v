module mux_2to1(
	input wire [31:0] imm_input,
	input wire [31:0] reg_input,
	input select,
	output wire [31:0] out
);
	assign out = select ? imm_input : reg_input;
endmodule	
