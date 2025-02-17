module datapath(
	input clk, enable, reset, select,
	input [31:0] instruction,
	input [4:0] rs1,rs2,rdi,
	input [31:0] reg_input,
	output reg [31:0] data_out1, data_out2,imm_out,
	output reg [3:0] sel_bit,
	output wenb, rs2_imm_sel
);
	wire [31:0] imm;
    	wire priority_out;
    	wire mux_select;
	
	register_file reg_file(
		.data_in(instruction),
		.clk(clk),
		.rs1(rs1),
		.rs2(rs2),
		.rd_select(rdi),
		.data_out1(data_out1),
		.data_out2(data_out2)
	);
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
		.out(imm_out)
	);
		
	rs2_or_imm control_for_imm(
		.rs2(data_out2),
		.imm(imm_out),
		.dataB(data_out2),
		.select(rs2_imm_sel)
	);
	
	control_unit cu (
		.data_in(instruction),
		.sel_bit(sel_bit),
		.wenb(wenb),
		.rs2_imm_sel(rs2_imm_sel)
		
		
	)
