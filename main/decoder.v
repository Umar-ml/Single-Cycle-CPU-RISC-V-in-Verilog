module decoder(
	input [31:0] data_in,
	output [4:0] rs1,rs2,rdi
);
	assign rdi = data_in[11:7];
	assign rs1 = data_in[19:15];
	assign rs2 = data_in[24:20];
endmodule
