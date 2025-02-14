module j_type_instruction (
    input  [31:0] instruction,
    output [6:0] opcode,
    output [4:0] rd,
    output reg [31:0] imm
);
    assign opcode = instruction[6:0];   
    assign rd     = instruction[11:7];  

    always @(*) begin
        imm = {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], 1'b0};
    end
endmodule

