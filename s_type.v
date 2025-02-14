module s_type_instruction(
    input  [31:0] instruction,
    output [6:0] opcode,
    output [2:0] funct3,
    output [4:0] rs1, rs2,
    output reg [31:0] imm  // Sign-extended immediate
);
    assign opcode  = instruction[6:0];   
    assign funct3  = instruction[14:12]; 
    assign rs1     = instruction[19:15]; 
    assign rs2     = instruction[24:20]; 

    always @(*) begin
        imm = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]}; // Sign-extend
    end
endmodule

