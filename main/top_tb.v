module pc_tb;
  reg clk;
  reg rst, enable;
  wire [4:0] rs1, rs2, rdi;
  wire [31:0] pc, alu_out, out_1, pc_imm, pc_plus4,rs1_plus_imm;
  wire [31:0] instruction;
  wire [31:0] immm, dataA, dataB, outdata_store, read_data, outputt;
  wire [3:0] sel_bit;
  wire [1:0] sel_bit_mux;
  wire [7:0] in;
  wire [2:0] out_for;
  wire addr, sub, sllr, sltr, sltur, xorr, srlr, srar, orr, andr;
  wire addi, slli, slti, sltui, xori, srli, srai, ori, andi;
  wire sw, sh, sb, lb, lh, lw, lbu, lhu;
  wire jal, jalr;
  wire beq, bne, blt, bge, bltu, bgeu;
  wire add, sll, slt, sltu, xorrr, srl, sra, orrr, andd;
  wire out0, out1, out2, out3;
  wire wenb, rs2_imm_sel;
  wire lui_enb, auipc_wenb, load_enb, jal_enb, branch_enb, in_to_pr;
  wire priority_out, addwith;
  wire branch_taken;

  fetch uut(
    .clk(clk),
    .rst(rst),
    .sel_bit_mux(sel_bit_mux),
    .pc_plus_4(pc_plus4),
    .pc_plus_imm(pc_imm),
    .rs1_plus_imm(rs1_plus_imm),
    .pc_plus_imm_2(pc_imm)
  );
  
  decoder decc(
    .data_in(uut.IM.instruction),
    .rs1(rs1),
    .rs2(rs2),
    .rdi(rdi)
  );
  
  immediate_generator imm(
    .instruction(uut.IM.instruction),
    .imm(immm),
    .priority_out(priority_out)
  );
  
  register_file regg(
    .clk(clk),
    .reset(rst),
    .enable(enable),
    .data_in(outputt),
    .rs1(rs1),
    .rs2(rs2),
    .rd_select(rdi),
    .data_out1(dataA),
    .data_out2(dataB)
  );
  
  alu aluu(
    .dataA(dataA),
    .dataB(out_1),
    .selector(sel_bit),
    .out(alu_out),
    .branch_taken(branch_taken)
  );
  
  mux_2to1 mx2(
    .reg_input(dataB),
    .imm_input(immm),
    .select(rs2_imm_sel),
    .out(out_1)
  );
  
  control_unit cuu(
    .addr(addr),
    .sub(sub),
    .sllr(sllr),
    .sltr(sltr),
    .sltur(sltur),
    .xorr(xorr),
    .srlr(srlr),
    .srar(srar),
    .orr(orr),
    .andr(andr),
    .addi(addi),
    .slli(slli),
    .slti(slti),
    .sltui(sltui),
    .xori(xori),
    .srli(srli),
    .srai(srai),
    .ori(ori),
    .andi(andi),
    .sw(sw),
    .sh(sh),
    .sb(sb),
    .lb(lb),
    .lh(lh),
    .lw(lw),
    .lbu(lbu),
    .lhu(lhu),
    .jal(jal),
    .jalr(jalr),
    .beq(beq),
    .bne(bne),
    .blt(blt),
    .bge(bge),
    .bltu(bltu),
    .bgeu(bgeu),
    .add(add),
    .sll(sll),
    .slt(slt),
    .sltu(sltu),
    .xorrr(xorrr),
    .srl(srl),
    .sra(sra),
    .orrr(orrr),
    .andd(andd),
    .out0(out0),
    .out1(out1),
    .out2(out2),
    .out3(out3),
    .data_in(uut.IM.instruction),
    .sel_bit(sel_bit),
    .wenb(wenb),
    .rs2_imm_sel(rs2_imm_sel),
    .jal_enb(jal_enb),
    .load_enb(load_enb),
    .branch_enb(branch_enb),
    .auipc_wenb(auipc_wenb),
    .sel_bit_mux(sel_bit_mux),
    .lui_enb(lui_enb),
    .addwith(addwith),
    .in_to_pr(in_to_pr)
  );
  
  mux_rs2 muxx(
    .rs2(dataB),
    .sel_bit(sel_bit),
    .output_data_forstore(outdata_store)
  );
  
  data_memory dmeme(
    .clk(clk),
    .load_enb(load_enb),
    .sb(sb),
    .sh(sh),
    .sw(sw),
    .lb(lb),
    .lh(lh),
    .lw(lw),
    .lbu(lbu),
    .lhu(lhu),
    .address(alu_out),
    .write_data(dataB),
    .read_data(read_data)
  );
  
  adder_for_auipc adderr(
    .pc_for_auipc(uut.PC.pc_out),
    .imm_for_btype(immm),
    .pc_plus_imm_for_auipc(pc_imm)
  );
  
  priority_encoder_8to3 pr_tomux(
    .alu_result(1'b1),
    .load_enable(load_enb),
    .jal_enb(jal_enb),
    .enable_for_auipc(branch_taken),
    .lui_enable(lui_enb),
    .sel(out_for)
  );
  
  mux_8to1 mux8(
    .sel(out_for),
    .alu_result(alu_out),
    .load_result(read_data),
    .pc_plus_4(uut.PC.pc_out),
    .pc_plus_imm(pc_imm),
    .imm_for_b_type(immm),
    .out(outputt)
  );
  
  pc_plus_4 pc_4(
    .pc(uut.PC.pc_out),
    .pc_plus4(pc_plus4)
  );
  
  rs1_plus_imm rs_imm(
    .rs1(dataA),
    .imm_input(immm),
    .rs1_plus_im(rs1_plus_imm)
  );
  
 
  

  always #5 clk = ~clk;
  
  initial begin
    $dumpfile("pc_tb.vcd");
    $dumpvars(0, pc_tb);
    
    clk = 0;
    rst = 1;
    enable = 0;
    #10 rst = 0;
    
    #5 enable = 1;  // Enable register writes after reset
    
    #100;
    
    $finish;
  end
  
  initial begin
    $monitor("Time: %t | PC: %h | Instruction: %h | rs1: %d | rs2: %d | rdi: %d | immediate: %d | dataA: %d | dataB: %d | aluout: %d", 
             $time, uut.PC.pc_out, uut.IM.instruction, rs1, rs2, rdi, immm, dataA, out_1, alu_out);
  end
endmodule

