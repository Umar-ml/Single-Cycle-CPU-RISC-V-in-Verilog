module alu(
	input [31:0] dataA, dataB,
	input [3:0] selector,
	output reg [31:0] out	
);
	always @(*)
	begin
		case(selector)
			4'b0000: out = dataA + dataB; //add
			4'b0001: out = dataA << dataB[5:0]; // sll
			4'b0010: out = (dataA < dataB) ? 32'b1 : 32'b0; // slt
			4'b0011: out = ($unsigned(dataA) < $unsigned(dataB)) ? 32'b1 : 32'b0;   // sltu
			4'b0100: out = dataA ^ dataB; // xorout
			4'b0101: out = dataA >> dataB[4:0]; // SRL
			4'b0110: out = dataA | dataB; // or out
			4'b0111: out = dataA & dataB; // and out
			4'b1000: out = dataA - dataB; //sub
			4'b1001: out = $signed(dataA) >>> dataB[4:0]; //SRA
			// Branch operations
			4'b1010: out = (dataA == dataB) ? 32'b1 : 32'b0; // BEQ
            		4'b1011: out = (dataA != dataB) ? 32'b1 : 32'b0; // BNE
            		4'b1100: out = ($signed(dataA) < $signed(dataB)) ? 32'b1 : 32'b0; // BLT
            		4'b1101: out = ($signed(dataA) >= $signed(dataB)) ? 32'b1 : 32'b0; // BGE
            		4'b1110: out = (dataA < dataB) ? 32'b1 : 32'b0; // BLTU (unsigned)
            		4'b1111: out = (dataA >= dataB) ? 32'b1 : 32'b0; // BGEU (unsigned)
			
			default: out = 32'b0;
		endcase
	end
	
endmodule
			
