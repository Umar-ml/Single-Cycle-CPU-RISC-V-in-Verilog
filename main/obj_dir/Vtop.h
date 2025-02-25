// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(fetch__02Eclk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(datapath__02Eclk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(rs1,4,0);
    VL_OUT8(rs2,4,0);
    VL_OUT8(rdi,4,0);
    VL_OUT8(sel_bit,3,0);
    VL_OUT8(wenb,0,0);
    VL_OUT8(rs2_imm_sel,0,0);
    VL_OUT8(jal_enb,0,0);
    VL_OUT8(load_enb,0,0);
    VL_OUT8(branch_enb,0,0);
    VL_OUT8(auipc_wenb,0,0);
    VL_OUT8(lui_enb,0,0);
    VL_OUT8(branch_taken,0,0);
    VL_IN8(enable,0,0);
    VL_IN8(select,0,0);
    VL_IN8(pc_write,0,0);
    VL_OUT8(sel_bit_mux,1,0);
    VL_OUT8(inp,4,0);
    VL_OUT8(input_to_mux,2,0);
    VL_OUT8(sb,0,0);
    VL_OUT8(sh,0,0);
    VL_OUT8(sw,0,0);
    VL_OUT8(lb,0,0);
    VL_OUT8(lh,0,0);
    VL_OUT8(lw,0,0);
    VL_OUT8(lbu,0,0);
    VL_OUT8(lhu,0,0);
    VL_OUT8(addr,0,0);
    VL_OUT8(sub,0,0);
    VL_OUT8(sllr,0,0);
    VL_OUT8(sltr,0,0);
    VL_OUT8(sltur,0,0);
    VL_OUT8(xorr,0,0);
    VL_OUT8(srlr,0,0);
    VL_OUT8(srar,0,0);
    VL_OUT8(orr,0,0);
    VL_OUT8(andr,0,0);
    VL_OUT8(addi,0,0);
    VL_OUT8(slli,0,0);
    VL_OUT8(slti,0,0);
    VL_OUT8(sltui,0,0);
    VL_OUT8(xori,0,0);
    VL_OUT8(srli,0,0);
    VL_OUT8(srai,0,0);
    VL_OUT8(ori,0,0);
    VL_OUT8(andi,0,0);
    VL_OUT8(in_to_pr,0,0);
    VL_OUT8(jal,0,0);
    VL_OUT8(jalr,0,0);
    VL_OUT8(beq,0,0);
    VL_OUT8(bne,0,0);
    VL_OUT8(blt,0,0);
    VL_OUT8(bge,0,0);
    VL_OUT8(bltu,0,0);
    VL_OUT8(bgeu,0,0);
    VL_OUT8(add,0,0);
    VL_OUT8(sll,0,0);
    VL_OUT8(slt,0,0);
    VL_OUT8(sltu,0,0);
    VL_OUT8(xorrr,0,0);
    VL_OUT8(srl,0,0);
    VL_OUT8(sra,0,0);
    VL_OUT8(orrr,0,0);
    VL_OUT8(andd,0,0);
    VL_OUT8(out0,0,0);
    VL_OUT8(out1,0,0);
    VL_OUT8(out2,0,0);
    VL_OUT8(out3,0,0);
    VL_IN(instruction,31,0);
    VL_OUT(reg_input,31,0);
    VL_OUT(load_result,31,0);
    VL_OUT(pc_plus_4,31,0);
    VL_OUT(pc_plus_imm,31,0);
    VL_OUT(imm_for_b_type,31,0);
    VL_OUT(data_out1,31,0);
    VL_OUT(data_out2,31,0);
    VL_OUT(imm_out,31,0);
    VL_OUT(alu_out,31,0);
    VL_OUT(output_data_forstore,31,0);
    VL_OUT(pc_plus_imm_for_auipc,31,0);
    VL_OUT(inst,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ datapath__DOT__priority_out;
    IData/*31:0*/ datapath__DOT__data_out3;
    IData/*31:0*/ datapath__DOT__imm;
    IData/*31:0*/ datapath__DOT__pc_out;
    IData/*31:0*/ datapath__DOT__pc_next;
    IData/*31:0*/ fetch__DOT__IM__DOT__memory[256];
    IData/*31:0*/ datapath__DOT__imem__DOT__memory[256];
    IData/*31:0*/ datapath__DOT__reg_file__DOT__registers[32];
    CData/*7:0*/ datapath__DOT__dmem__DOT__memory[4096];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*3:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__fetch__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    CData/*0:0*/ __Vclklast__TOP__datapath__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    IData/*31:0*/ __Vchglast__TOP__reg_input;
    CData/*0:0*/ __Vtablechg1[16];
    static CData/*1:0*/ __Vtable1_sel_bit_mux[16];
    static CData/*2:0*/ __Vtable2_input_to_mux[32];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__7(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
