module i_type_instruction(
    input [31:0] instruction,
    output [6:0] opcode, 
    output [4:0] rd,
    output [4:0] rs1,
    output [2:0] funct3,
  output [11:0] imm
);
    assign opcode = instruction[6:0];   
    assign rd     = instruction[11:7];  
    assign funct3 = instruction[14:12]; 
    assign rs1    = instruction[19:15]; 
  always @(*)
    begin
      assign imm = {{20{instruction[31]}},instruction[31:20]};
    end
endmodule

