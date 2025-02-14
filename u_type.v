module u_type_instruction (
    input  [31:0] instruction,
    output [6:0] opcode,
    output [4:0] rd,
    output reg [31:0] imm
);
    assign opcode = instruction[6:0];   
    assign rd     = instruction[11:7];  

    always @(*) begin
        imm = {instruction[31:12], 12'b0};  // Zero-extend and shift left by 12 bits
    end
endmodule

