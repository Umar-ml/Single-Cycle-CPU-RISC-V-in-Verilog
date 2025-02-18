module immediate_generator(
	input [31:0] instruction,
	output reg [31:0] imm,
	output reg priority_out
	);
	wire [6:0] opcode = instruction[6:0];
	always @(*)
		begin 
			case(opcode)
				7'h13, 7'h03, 7'h67:
				begin 
					imm = {{20{instruction[31]}},instruction[31:20]};
					priority_out = 1'b1;
				end
				7'h23:
				begin
					imm = {{20{instruction[31]}},instruction[31:25],instruction[11:7]};
					priority_out = 1'b1;
				end
				7'h63: 
				begin
                			imm = {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], 1'b0}; // Sign-extended
                			priority_out = 1'b1;
            			end
            			7'h37, 7'h17: 
            			begin
                			imm = {instruction[31:12], 12'b0}; // Left shift by 12 (not sign-extended)
                			priority_out = 1'b1;
            			end
            			7'h6F:
            			begin
                			imm = {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], 1'b0}; // Sign-extended
                			priority_out = 1'b1;
            			end
            			7'h33: 
            			begin
                			imm = 32'b0; 
                			priority_out = 1'b0; // Disable priority encoder
            			end
            			default: 
            			begin
                			imm = 32'b0; // Default case (if opcode is unknown)
                			priority_out = 1'b0; // Disable priority encoder
            			end
        		endcase
    		end
endmodule

