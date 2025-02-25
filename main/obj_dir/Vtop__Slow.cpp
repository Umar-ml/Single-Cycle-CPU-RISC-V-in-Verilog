// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========
CData/*1:0*/ Vtop::__Vtable1_sel_bit_mux[16];
CData/*2:0*/ Vtop::__Vtable2_input_to_mux[32];

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp1[4];
    WData/*127:0*/ __Vtemp2[4];
    // Body
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x696f6e73U;
    __Vtemp1[2U] = 0x72756374U;
    __Vtemp1[3U] = 0x696e7374U;
    VL_READMEM_N(true, 32, 256, 0, VL_CVT_PACK_STR_NW(4, __Vtemp1)
                 , vlTOPp->fetch__DOT__IM__DOT__memory
                 , 0, ~0ULL);
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x696f6e73U;
    __Vtemp2[2U] = 0x72756374U;
    __Vtemp2[3U] = 0x696e7374U;
    VL_READMEM_N(true, 32, 256, 0, VL_CVT_PACK_STR_NW(4, __Vtemp2)
                 , vlTOPp->datapath__DOT__imem__DOT__memory
                 , 0, ~0ULL);
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vtableidx2;
    // Body
    __Vtableidx2 = vlTOPp->inp;
    vlTOPp->input_to_mux = vlTOPp->__Vtable2_input_to_mux
        [__Vtableidx2];
    vlTOPp->addr = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (vlTOPp->instruction 
                                              >> 5U)) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (~ (vlTOPp->instruction 
                                                   >> 0xcU))) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (~ (vlTOPp->instruction 
                                                   >> 0xeU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    if ((0x40U & vlTOPp->instruction)) {
        vlTOPp->datapath__DOT__priority_out = (1U & 
                                               ((vlTOPp->instruction 
                                                 >> 5U) 
                                                & ((~ 
                                                    (vlTOPp->instruction 
                                                     >> 4U)) 
                                                   & ((8U 
                                                       & vlTOPp->instruction)
                                                       ? 
                                                      ((vlTOPp->instruction 
                                                        >> 2U) 
                                                       & ((vlTOPp->instruction 
                                                           >> 1U) 
                                                          & vlTOPp->instruction))
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->instruction)
                                                        ? 
                                                       ((vlTOPp->instruction 
                                                         >> 1U) 
                                                        & vlTOPp->instruction)
                                                        : 
                                                       ((vlTOPp->instruction 
                                                         >> 1U) 
                                                        & vlTOPp->instruction))))));
        vlTOPp->datapath__DOT__imm = ((0x20U & vlTOPp->instruction)
                                       ? ((0x10U & vlTOPp->instruction)
                                           ? 0U : (
                                                   (8U 
                                                    & vlTOPp->instruction)
                                                    ? 
                                                   ((4U 
                                                     & vlTOPp->instruction)
                                                     ? 
                                                    ((2U 
                                                      & vlTOPp->instruction)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->instruction)
                                                       ? 
                                                      ((0xffe00000U 
                                                        & ((- (IData)(
                                                                      (1U 
                                                                       & (vlTOPp->instruction 
                                                                          >> 0x1fU)))) 
                                                           << 0x15U)) 
                                                       | ((0x100000U 
                                                           & (vlTOPp->instruction 
                                                              >> 0xbU)) 
                                                          | ((0xff000U 
                                                              & vlTOPp->instruction) 
                                                             | ((0x800U 
                                                                 & (vlTOPp->instruction 
                                                                    >> 9U)) 
                                                                | (0x7feU 
                                                                   & (vlTOPp->instruction 
                                                                      >> 0x14U))))))
                                                       : 0U)
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->instruction)
                                                     ? 
                                                    ((2U 
                                                      & vlTOPp->instruction)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->instruction)
                                                       ? 
                                                      ((0xfffff000U 
                                                        & ((- (IData)(
                                                                      (1U 
                                                                       & (vlTOPp->instruction 
                                                                          >> 0x1fU)))) 
                                                           << 0xcU)) 
                                                       | (0xfffU 
                                                          & (vlTOPp->instruction 
                                                             >> 0x14U)))
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->instruction)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->instruction)
                                                       ? 
                                                      ((0xffffe000U 
                                                        & ((- (IData)(
                                                                      (1U 
                                                                       & (vlTOPp->instruction 
                                                                          >> 0x1fU)))) 
                                                           << 0xdU)) 
                                                       | ((0x1000U 
                                                           & (vlTOPp->instruction 
                                                              >> 0x13U)) 
                                                          | ((0x800U 
                                                              & (vlTOPp->instruction 
                                                                 << 4U)) 
                                                             | ((0x7e0U 
                                                                 & (vlTOPp->instruction 
                                                                    >> 0x14U)) 
                                                                | (0x1eU 
                                                                   & (vlTOPp->instruction 
                                                                      >> 7U))))))
                                                       : 0U)
                                                      : 0U))))
                                       : 0U);
    } else {
        vlTOPp->datapath__DOT__priority_out = (1U & 
                                               ((0x20U 
                                                 & vlTOPp->instruction)
                                                 ? 
                                                ((0x10U 
                                                  & vlTOPp->instruction)
                                                  ? 
                                                 ((~ 
                                                   (vlTOPp->instruction 
                                                    >> 3U)) 
                                                  & ((vlTOPp->instruction 
                                                      >> 2U) 
                                                     & ((vlTOPp->instruction 
                                                         >> 1U) 
                                                        & vlTOPp->instruction)))
                                                  : 
                                                 ((~ 
                                                   (vlTOPp->instruction 
                                                    >> 3U)) 
                                                  & ((~ 
                                                      (vlTOPp->instruction 
                                                       >> 2U)) 
                                                     & ((vlTOPp->instruction 
                                                         >> 1U) 
                                                        & vlTOPp->instruction))))
                                                 : 
                                                ((0x10U 
                                                  & vlTOPp->instruction)
                                                  ? 
                                                 ((~ 
                                                   (vlTOPp->instruction 
                                                    >> 3U)) 
                                                  & ((4U 
                                                      & vlTOPp->instruction)
                                                      ? 
                                                     ((vlTOPp->instruction 
                                                       >> 1U) 
                                                      & vlTOPp->instruction)
                                                      : 
                                                     ((vlTOPp->instruction 
                                                       >> 1U) 
                                                      & vlTOPp->instruction)))
                                                  : 
                                                 ((~ 
                                                   (vlTOPp->instruction 
                                                    >> 3U)) 
                                                  & ((~ 
                                                      (vlTOPp->instruction 
                                                       >> 2U)) 
                                                     & ((vlTOPp->instruction 
                                                         >> 1U) 
                                                        & vlTOPp->instruction))))));
        vlTOPp->datapath__DOT__imm = ((0x20U & vlTOPp->instruction)
                                       ? ((0x10U & vlTOPp->instruction)
                                           ? ((8U & vlTOPp->instruction)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->instruction)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->instruction)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->instruction)
                                                     ? 
                                                    (0xfffff000U 
                                                     & vlTOPp->instruction)
                                                     : 0U)
                                                    : 0U)
                                                   : 0U))
                                           : ((8U & vlTOPp->instruction)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->instruction)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->instruction)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->instruction)
                                                     ? 
                                                    ((0xfffff000U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->instruction 
                                                                        >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | ((0xfe0U 
                                                         & (vlTOPp->instruction 
                                                            >> 0x14U)) 
                                                        | (0x1fU 
                                                           & (vlTOPp->instruction 
                                                              >> 7U))))
                                                     : 0U)
                                                    : 0U))))
                                       : ((0x10U & vlTOPp->instruction)
                                           ? ((8U & vlTOPp->instruction)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->instruction)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->instruction)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->instruction)
                                                     ? 
                                                    (0xfffff000U 
                                                     & vlTOPp->instruction)
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->instruction)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->instruction)
                                                     ? 
                                                    ((0xfffff000U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->instruction 
                                                                        >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | (0xfffU 
                                                        & (vlTOPp->instruction 
                                                           >> 0x14U)))
                                                     : 0U)
                                                    : 0U)))
                                           : ((8U & vlTOPp->instruction)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->instruction)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->instruction)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->instruction)
                                                     ? 
                                                    ((0xfffff000U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->instruction 
                                                                        >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | (0xfffU 
                                                        & (vlTOPp->instruction 
                                                           >> 0x14U)))
                                                     : 0U)
                                                    : 0U)))));
    }
    vlTOPp->lui_enb = (1U & (((((vlTOPp->instruction 
                                 >> 2U) & (~ (vlTOPp->instruction 
                                              >> 3U))) 
                               & (vlTOPp->instruction 
                                  >> 4U)) & (vlTOPp->instruction 
                                             >> 5U)) 
                             & (~ (vlTOPp->instruction 
                                   >> 6U))));
    vlTOPp->auipc_wenb = (1U & (((((vlTOPp->instruction 
                                    >> 2U) & (~ (vlTOPp->instruction 
                                                 >> 3U))) 
                                  & (vlTOPp->instruction 
                                     >> 4U)) & (~ (vlTOPp->instruction 
                                                   >> 5U))) 
                                & (~ (vlTOPp->instruction 
                                      >> 6U))));
    vlTOPp->beq = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (~ (vlTOPp->instruction 
                                     >> 4U))) & (vlTOPp->instruction 
                                                 >> 5U)) 
                             & (vlTOPp->instruction 
                                >> 6U)) & (~ (vlTOPp->instruction 
                                              >> 0xcU))) 
                           & (~ (vlTOPp->instruction 
                                 >> 0xdU))) & (~ (vlTOPp->instruction 
                                                  >> 0xeU))) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->bne = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (~ (vlTOPp->instruction 
                                     >> 4U))) & (vlTOPp->instruction 
                                                 >> 5U)) 
                             & (vlTOPp->instruction 
                                >> 6U)) & (vlTOPp->instruction 
                                           >> 0xcU)) 
                           & (~ (vlTOPp->instruction 
                                 >> 0xdU))) & (~ (vlTOPp->instruction 
                                                  >> 0xeU))) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->blt = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (~ (vlTOPp->instruction 
                                     >> 4U))) & (vlTOPp->instruction 
                                                 >> 5U)) 
                             & (vlTOPp->instruction 
                                >> 6U)) & (~ (vlTOPp->instruction 
                                              >> 0xcU))) 
                           & (~ (vlTOPp->instruction 
                                 >> 0xdU))) & (vlTOPp->instruction 
                                               >> 0xeU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->bge = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (~ (vlTOPp->instruction 
                                     >> 4U))) & (vlTOPp->instruction 
                                                 >> 5U)) 
                             & (vlTOPp->instruction 
                                >> 6U)) & (vlTOPp->instruction 
                                           >> 0xcU)) 
                           & (~ (vlTOPp->instruction 
                                 >> 0xdU))) & (vlTOPp->instruction 
                                               >> 0xeU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->bltu = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (~ (vlTOPp->instruction 
                                      >> 4U))) & (vlTOPp->instruction 
                                                  >> 5U)) 
                              & (vlTOPp->instruction 
                                 >> 6U)) & (~ (vlTOPp->instruction 
                                               >> 0xcU))) 
                            & (vlTOPp->instruction 
                               >> 0xdU)) & (vlTOPp->instruction 
                                            >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->bgeu = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (~ (vlTOPp->instruction 
                                      >> 4U))) & (vlTOPp->instruction 
                                                  >> 5U)) 
                              & (vlTOPp->instruction 
                                 >> 6U)) & (vlTOPp->instruction 
                                            >> 0xcU)) 
                            & (vlTOPp->instruction 
                               >> 0xdU)) & (vlTOPp->instruction 
                                            >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->addi = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (~ (vlTOPp->instruction 
                                                 >> 5U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (~ (vlTOPp->instruction 
                                                   >> 0xcU))) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (~ (vlTOPp->instruction 
                                                   >> 0xeU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->jal = (1U & (((((((((vlTOPp->instruction 
                                 >> 2U) & (vlTOPp->instruction 
                                           >> 3U)) 
                               & (~ (vlTOPp->instruction 
                                     >> 4U))) & (vlTOPp->instruction 
                                                 >> 5U)) 
                             & (vlTOPp->instruction 
                                >> 6U)) & (~ (vlTOPp->instruction 
                                              >> 0xcU))) 
                           & (~ (vlTOPp->instruction 
                                 >> 0xdU))) & (~ (vlTOPp->instruction 
                                                  >> 0xeU))) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->jalr = (1U & (((((((((vlTOPp->instruction 
                                  >> 2U) & (~ (vlTOPp->instruction 
                                               >> 3U))) 
                                & (~ (vlTOPp->instruction 
                                      >> 4U))) & (vlTOPp->instruction 
                                                  >> 5U)) 
                              & (vlTOPp->instruction 
                                 >> 6U)) & (~ (vlTOPp->instruction 
                                               >> 0xcU))) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (~ (vlTOPp->instruction 
                                                   >> 0xeU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->rs1 = (0x1fU & (vlTOPp->instruction >> 0xfU));
    vlTOPp->lb = (1U & (((((((((~ (vlTOPp->instruction 
                                   >> 2U)) & (~ (vlTOPp->instruction 
                                                 >> 3U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 4U))) & (~ (vlTOPp->instruction 
                                                   >> 5U))) 
                            & (~ (vlTOPp->instruction 
                                  >> 6U))) & (~ (vlTOPp->instruction 
                                                 >> 0xcU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0xdU))) & (~ (vlTOPp->instruction 
                                                 >> 0xeU))) 
                        & (~ (vlTOPp->instruction >> 0x1eU))));
    vlTOPp->lh = (1U & (((((((((~ (vlTOPp->instruction 
                                   >> 2U)) & (~ (vlTOPp->instruction 
                                                 >> 3U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 4U))) & (~ (vlTOPp->instruction 
                                                   >> 5U))) 
                            & (~ (vlTOPp->instruction 
                                  >> 6U))) & (vlTOPp->instruction 
                                              >> 0xcU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0xdU))) & (~ (vlTOPp->instruction 
                                                 >> 0xeU))) 
                        & (~ (vlTOPp->instruction >> 0x1eU))));
    vlTOPp->lw = (1U & (((((((((~ (vlTOPp->instruction 
                                   >> 2U)) & (~ (vlTOPp->instruction 
                                                 >> 3U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 4U))) & (~ (vlTOPp->instruction 
                                                   >> 5U))) 
                            & (~ (vlTOPp->instruction 
                                  >> 6U))) & (~ (vlTOPp->instruction 
                                                 >> 0xcU))) 
                          & (vlTOPp->instruction >> 0xdU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0xeU))) & (~ (vlTOPp->instruction 
                                                >> 0x1eU))));
    vlTOPp->lbu = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (~ (vlTOPp->instruction 
                                     >> 4U))) & (~ 
                                                 (vlTOPp->instruction 
                                                  >> 5U))) 
                             & (~ (vlTOPp->instruction 
                                   >> 6U))) & (~ (vlTOPp->instruction 
                                                  >> 0xcU))) 
                           & (vlTOPp->instruction >> 0xdU)) 
                          & (vlTOPp->instruction >> 0xeU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->lhu = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (~ (vlTOPp->instruction 
                                     >> 4U))) & (~ 
                                                 (vlTOPp->instruction 
                                                  >> 5U))) 
                             & (~ (vlTOPp->instruction 
                                   >> 6U))) & (vlTOPp->instruction 
                                               >> 0xcU)) 
                           & (~ (vlTOPp->instruction 
                                 >> 0xdU))) & (vlTOPp->instruction 
                                               >> 0xeU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->rs2 = (0x1fU & (vlTOPp->instruction >> 0x14U));
    vlTOPp->sub = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (vlTOPp->instruction 
                                  >> 4U)) & (vlTOPp->instruction 
                                             >> 5U)) 
                             & (~ (vlTOPp->instruction 
                                   >> 6U))) & (~ (vlTOPp->instruction 
                                                  >> 0xcU))) 
                           & (~ (vlTOPp->instruction 
                                 >> 0xdU))) & (~ (vlTOPp->instruction 
                                                  >> 0xeU))) 
                         & (vlTOPp->instruction >> 0x1eU)));
    vlTOPp->sltr = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (vlTOPp->instruction 
                                              >> 5U)) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (~ (vlTOPp->instruction 
                                                   >> 0xcU))) 
                            & (vlTOPp->instruction 
                               >> 0xdU)) & (~ (vlTOPp->instruction 
                                               >> 0xeU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->sllr = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (vlTOPp->instruction 
                                              >> 5U)) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (~ (vlTOPp->instruction 
                                                   >> 0xeU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->xorr = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (vlTOPp->instruction 
                                              >> 5U)) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (~ (vlTOPp->instruction 
                                                   >> 0xcU))) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (vlTOPp->instruction 
                                                >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->slti = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (~ (vlTOPp->instruction 
                                                 >> 5U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (~ (vlTOPp->instruction 
                                                   >> 0xcU))) 
                            & (vlTOPp->instruction 
                               >> 0xdU)) & (~ (vlTOPp->instruction 
                                               >> 0xeU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->slli = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (~ (vlTOPp->instruction 
                                                 >> 5U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (~ (vlTOPp->instruction 
                                                   >> 0xeU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->xori = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (~ (vlTOPp->instruction 
                                                 >> 5U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (~ (vlTOPp->instruction 
                                                   >> 0xcU))) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (vlTOPp->instruction 
                                                >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->sltur = (1U & (((((((((~ (vlTOPp->instruction 
                                      >> 2U)) & (~ 
                                                 (vlTOPp->instruction 
                                                  >> 3U))) 
                                 & (vlTOPp->instruction 
                                    >> 4U)) & (vlTOPp->instruction 
                                               >> 5U)) 
                               & (~ (vlTOPp->instruction 
                                     >> 6U))) & (vlTOPp->instruction 
                                                 >> 0xcU)) 
                             & (vlTOPp->instruction 
                                >> 0xdU)) & (~ (vlTOPp->instruction 
                                                >> 0xeU))) 
                           & (~ (vlTOPp->instruction 
                                 >> 0x1eU))));
    vlTOPp->orr = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (vlTOPp->instruction 
                                  >> 4U)) & (vlTOPp->instruction 
                                             >> 5U)) 
                             & (~ (vlTOPp->instruction 
                                   >> 6U))) & (~ (vlTOPp->instruction 
                                                  >> 0xcU))) 
                           & (vlTOPp->instruction >> 0xdU)) 
                          & (vlTOPp->instruction >> 0xeU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->srlr = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (vlTOPp->instruction 
                                              >> 5U)) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (vlTOPp->instruction 
                                                >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->sltui = (1U & (((((((((~ (vlTOPp->instruction 
                                      >> 2U)) & (~ 
                                                 (vlTOPp->instruction 
                                                  >> 3U))) 
                                 & (vlTOPp->instruction 
                                    >> 4U)) & (~ (vlTOPp->instruction 
                                                  >> 5U))) 
                               & (~ (vlTOPp->instruction 
                                     >> 6U))) & (vlTOPp->instruction 
                                                 >> 0xcU)) 
                             & (vlTOPp->instruction 
                                >> 0xdU)) & (~ (vlTOPp->instruction 
                                                >> 0xeU))) 
                           & (~ (vlTOPp->instruction 
                                 >> 0x1eU))));
    vlTOPp->ori = (1U & (((((((((~ (vlTOPp->instruction 
                                    >> 2U)) & (~ (vlTOPp->instruction 
                                                  >> 3U))) 
                               & (vlTOPp->instruction 
                                  >> 4U)) & (~ (vlTOPp->instruction 
                                                >> 5U))) 
                             & (~ (vlTOPp->instruction 
                                   >> 6U))) & (~ (vlTOPp->instruction 
                                                  >> 0xcU))) 
                           & (vlTOPp->instruction >> 0xdU)) 
                          & (vlTOPp->instruction >> 0xeU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0x1eU))));
    vlTOPp->srli = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (~ (vlTOPp->instruction 
                                                 >> 5U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (vlTOPp->instruction 
                                                >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->srar = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (vlTOPp->instruction 
                                              >> 5U)) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (vlTOPp->instruction 
                                                >> 0xeU)) 
                          & (vlTOPp->instruction >> 0x1eU)));
    vlTOPp->andr = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (vlTOPp->instruction 
                                              >> 5U)) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (vlTOPp->instruction 
                               >> 0xdU)) & (vlTOPp->instruction 
                                            >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->srai = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (~ (vlTOPp->instruction 
                                                 >> 5U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (~ (vlTOPp->instruction 
                                  >> 0xdU))) & (vlTOPp->instruction 
                                                >> 0xeU)) 
                          & (vlTOPp->instruction >> 0x1eU)));
    vlTOPp->andi = (1U & (((((((((~ (vlTOPp->instruction 
                                     >> 2U)) & (~ (vlTOPp->instruction 
                                                   >> 3U))) 
                                & (vlTOPp->instruction 
                                   >> 4U)) & (~ (vlTOPp->instruction 
                                                 >> 5U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 6U))) & (vlTOPp->instruction 
                                                >> 0xcU)) 
                            & (vlTOPp->instruction 
                               >> 0xdU)) & (vlTOPp->instruction 
                                            >> 0xeU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0x1eU))));
    vlTOPp->rdi = (0x1fU & (vlTOPp->instruction >> 7U));
    vlTOPp->sw = (1U & (((((((((~ (vlTOPp->instruction 
                                   >> 2U)) & (~ (vlTOPp->instruction 
                                                 >> 3U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 4U))) & (vlTOPp->instruction 
                                                >> 5U)) 
                            & (~ (vlTOPp->instruction 
                                  >> 6U))) & (~ (vlTOPp->instruction 
                                                 >> 0xcU))) 
                          & (vlTOPp->instruction >> 0xdU)) 
                         & (~ (vlTOPp->instruction 
                               >> 0xeU))) & (~ (vlTOPp->instruction 
                                                >> 0x1eU))));
    vlTOPp->sh = (1U & (((((((((~ (vlTOPp->instruction 
                                   >> 2U)) & (~ (vlTOPp->instruction 
                                                 >> 3U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 4U))) & (vlTOPp->instruction 
                                                >> 5U)) 
                            & (~ (vlTOPp->instruction 
                                  >> 6U))) & (vlTOPp->instruction 
                                              >> 0xcU)) 
                          & (~ (vlTOPp->instruction 
                                >> 0xdU))) & (~ (vlTOPp->instruction 
                                                 >> 0xeU))) 
                        & (~ (vlTOPp->instruction >> 0x1eU))));
    vlTOPp->sb = (1U & (((((((((~ (vlTOPp->instruction 
                                   >> 2U)) & (~ (vlTOPp->instruction 
                                                 >> 3U))) 
                              & (~ (vlTOPp->instruction 
                                    >> 4U))) & (vlTOPp->instruction 
                                                >> 5U)) 
                            & (~ (vlTOPp->instruction 
                                  >> 6U))) & (~ (vlTOPp->instruction 
                                                 >> 0xcU))) 
                          & (~ (vlTOPp->instruction 
                                >> 0xdU))) & (~ (vlTOPp->instruction 
                                                 >> 0xeU))) 
                        & (~ (vlTOPp->instruction >> 0x1eU))));
    vlTOPp->inst = vlTOPp->datapath__DOT__imem__DOT__memory
        [(0xffU & (vlTOPp->datapath__DOT__pc_out >> 2U))];
    vlTOPp->imm_out = ((IData)(vlTOPp->datapath__DOT__priority_out)
                        ? vlTOPp->datapath__DOT__imm
                        : vlTOPp->reg_input);
    vlTOPp->branch_enb = ((((((IData)(vlTOPp->beq) 
                              | (IData)(vlTOPp->bne)) 
                             | (IData)(vlTOPp->blt)) 
                            | (IData)(vlTOPp->bge)) 
                           | (IData)(vlTOPp->bltu)) 
                          | (IData)(vlTOPp->bgeu));
    vlTOPp->add = ((IData)(vlTOPp->addr) | (IData)(vlTOPp->addi));
    vlTOPp->jal_enb = ((IData)(vlTOPp->jal) | (IData)(vlTOPp->jalr));
    vlTOPp->data_out1 = ((0U == (IData)(vlTOPp->rs1))
                          ? 0U : vlTOPp->datapath__DOT__reg_file__DOT__registers
                         [vlTOPp->rs1]);
    vlTOPp->load_enb = (((((IData)(vlTOPp->lb) | (IData)(vlTOPp->lh)) 
                          | (IData)(vlTOPp->lw)) | (IData)(vlTOPp->lbu)) 
                        | (IData)(vlTOPp->lhu));
    vlTOPp->data_out2 = ((0U == (IData)(vlTOPp->rs2))
                          ? 0U : vlTOPp->datapath__DOT__reg_file__DOT__registers
                         [vlTOPp->rs2]);
    vlTOPp->slt = ((IData)(vlTOPp->sltr) | (IData)(vlTOPp->slti));
    vlTOPp->sll = ((IData)(vlTOPp->sllr) | (IData)(vlTOPp->slli));
    vlTOPp->xorrr = ((IData)(vlTOPp->xorr) | (IData)(vlTOPp->xori));
    vlTOPp->sltu = ((IData)(vlTOPp->sltur) | (IData)(vlTOPp->sltui));
    vlTOPp->orrr = ((IData)(vlTOPp->orr) | (IData)(vlTOPp->ori));
    vlTOPp->srl = ((IData)(vlTOPp->srlr) | (IData)(vlTOPp->srli));
    vlTOPp->sra = ((IData)(vlTOPp->srar) | (IData)(vlTOPp->srai));
    vlTOPp->andd = ((IData)(vlTOPp->andr) | (IData)(vlTOPp->andi));
    vlTOPp->wenb = (((((((((((((((((((((((((((((((IData)(vlTOPp->lw) 
                                                 | (IData)(vlTOPp->jal)) 
                                                | (IData)(vlTOPp->lh)) 
                                               | (IData)(vlTOPp->lb)) 
                                              | (IData)(vlTOPp->addr)) 
                                             | (IData)(vlTOPp->sub)) 
                                            | (IData)(vlTOPp->srar)) 
                                           | (IData)(vlTOPp->sllr)) 
                                          | (IData)(vlTOPp->orr)) 
                                         | (IData)(vlTOPp->andr)) 
                                        | (IData)(vlTOPp->sltur)) 
                                       | (IData)(vlTOPp->sltr)) 
                                      | (IData)(vlTOPp->srai)) 
                                     | (IData)(vlTOPp->xorr)) 
                                    | (IData)(vlTOPp->srlr)) 
                                   | (IData)(vlTOPp->andi)) 
                                  | (IData)(vlTOPp->auipc_wenb)) 
                                 | (IData)(vlTOPp->ori)) 
                                | (IData)(vlTOPp->xori)) 
                               | (IData)(vlTOPp->sltui)) 
                              | (IData)(vlTOPp->srli)) 
                             | (IData)(vlTOPp->slli)) 
                            | (IData)(vlTOPp->addi)) 
                           | (IData)(vlTOPp->slti)) 
                          | (IData)(vlTOPp->sb)) | (IData)(vlTOPp->sh)) 
                        | (IData)(vlTOPp->sw)) | (IData)(vlTOPp->lbu)) 
                      | (IData)(vlTOPp->lhu)) | (IData)(vlTOPp->jalr)) 
                    | (IData)(vlTOPp->lui_enb));
    vlTOPp->rs2_imm_sel = (((((((((((((((((((((IData)(vlTOPp->lui_enb) 
                                              | (IData)(vlTOPp->jal)) 
                                             | (IData)(vlTOPp->lb)) 
                                            | (IData)(vlTOPp->lh)) 
                                           | (IData)(vlTOPp->addi)) 
                                          | (IData)(vlTOPp->sh)) 
                                         | (IData)(vlTOPp->sb)) 
                                        | (IData)(vlTOPp->sw)) 
                                       | (IData)(vlTOPp->slli)) 
                                      | (IData)(vlTOPp->srai)) 
                                     | (IData)(vlTOPp->auipc_wenb)) 
                                    | (IData)(vlTOPp->ori)) 
                                   | (IData)(vlTOPp->andi)) 
                                  | (IData)(vlTOPp->srli)) 
                                 | (IData)(vlTOPp->xori)) 
                                | (IData)(vlTOPp->sltui)) 
                               | (IData)(vlTOPp->slti)) 
                              | (IData)(vlTOPp->lbu)) 
                             | (IData)(vlTOPp->lhu)) 
                            | (IData)(vlTOPp->jalr)) 
                           | (IData)(vlTOPp->lw));
    vlTOPp->pc_plus_imm_for_auipc = (vlTOPp->datapath__DOT__pc_out 
                                     + vlTOPp->imm_out);
    vlTOPp->in_to_pr = (1U & (~ (((IData)(vlTOPp->jal) 
                                  | (IData)(vlTOPp->jalr)) 
                                 | (IData)(vlTOPp->branch_enb))));
    vlTOPp->out3 = ((IData)(vlTOPp->sub) | (IData)(vlTOPp->sra));
    vlTOPp->out1 = ((((IData)(vlTOPp->slt) | (IData)(vlTOPp->sltu)) 
                     | (IData)(vlTOPp->orrr)) | (IData)(vlTOPp->andd));
    vlTOPp->out0 = (((((IData)(vlTOPp->sll) | (IData)(vlTOPp->sltu)) 
                      | (IData)(vlTOPp->srl)) | (IData)(vlTOPp->sra)) 
                    | (IData)(vlTOPp->andd));
    vlTOPp->out2 = (((((IData)(vlTOPp->xorrr) | (IData)(vlTOPp->srl)) 
                      | (IData)(vlTOPp->sra)) | (IData)(vlTOPp->orrr)) 
                    | (IData)(vlTOPp->andd));
    vlTOPp->datapath__DOT__data_out3 = ((IData)(vlTOPp->rs2_imm_sel)
                                         ? vlTOPp->imm_out
                                         : vlTOPp->data_out2);
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->in_to_pr) 
                             << 3U) | (((IData)(vlTOPp->branch_enb) 
                                        << 2U) | (((IData)(vlTOPp->jalr) 
                                                   << 1U) 
                                                  | (IData)(vlTOPp->jal))));
    if (vlTOPp->__Vtablechg1[vlTOPp->__Vtableidx1]) {
        vlTOPp->sel_bit_mux = vlTOPp->__Vtable1_sel_bit_mux
            [vlTOPp->__Vtableidx1];
    }
    vlTOPp->sel_bit = (((IData)(vlTOPp->out0) << 3U) 
                       | (((IData)(vlTOPp->out1) << 2U) 
                          | (((IData)(vlTOPp->out2) 
                              << 1U) | (IData)(vlTOPp->out3))));
    vlTOPp->branch_taken = 0U;
    if ((8U & (IData)(vlTOPp->sel_bit))) {
        if ((4U & (IData)(vlTOPp->sel_bit))) {
            vlTOPp->branch_taken = ((2U & (IData)(vlTOPp->sel_bit))
                                     ? ((1U & (IData)(vlTOPp->sel_bit))
                                         ? (vlTOPp->data_out1 
                                            >= vlTOPp->data_out2)
                                         : (vlTOPp->data_out1 
                                            < vlTOPp->data_out2))
                                     : ((1U & (IData)(vlTOPp->sel_bit))
                                         ? VL_GTES_III(1,32,32, vlTOPp->data_out1, vlTOPp->data_out2)
                                         : VL_LTS_III(1,32,32, vlTOPp->data_out1, vlTOPp->data_out2)));
        } else {
            if ((2U & (IData)(vlTOPp->sel_bit))) {
                vlTOPp->branch_taken = ((1U & (IData)(vlTOPp->sel_bit))
                                         ? (vlTOPp->data_out1 
                                            != vlTOPp->data_out2)
                                         : (vlTOPp->data_out1 
                                            == vlTOPp->data_out2));
            }
        }
    }
    vlTOPp->alu_out = ((8U & (IData)(vlTOPp->sel_bit))
                        ? ((4U & (IData)(vlTOPp->sel_bit))
                            ? ((2U & (IData)(vlTOPp->sel_bit))
                                ? ((1U & (IData)(vlTOPp->sel_bit))
                                    ? ((vlTOPp->data_out1 
                                        >= vlTOPp->data_out2)
                                        ? 1U : 0U) : 
                                   ((vlTOPp->data_out1 
                                     < vlTOPp->data_out2)
                                     ? 1U : 0U)) : 
                               ((1U & (IData)(vlTOPp->sel_bit))
                                 ? (VL_GTES_III(1,32,32, vlTOPp->data_out1, vlTOPp->data_out2)
                                     ? 1U : 0U) : (
                                                   VL_LTS_III(1,32,32, vlTOPp->data_out1, vlTOPp->data_out2)
                                                    ? 1U
                                                    : 0U)))
                            : ((2U & (IData)(vlTOPp->sel_bit))
                                ? ((1U & (IData)(vlTOPp->sel_bit))
                                    ? ((vlTOPp->data_out1 
                                        != vlTOPp->data_out2)
                                        ? 1U : 0U) : 
                                   ((vlTOPp->data_out1 
                                     == vlTOPp->data_out2)
                                     ? 1U : 0U)) : 
                               ((1U & (IData)(vlTOPp->sel_bit))
                                 ? VL_SHIFTRS_III(32,32,5, vlTOPp->data_out1, 
                                                  (0x1fU 
                                                   & vlTOPp->data_out2))
                                 : (vlTOPp->data_out1 
                                    - vlTOPp->data_out2))))
                        : ((4U & (IData)(vlTOPp->sel_bit))
                            ? ((2U & (IData)(vlTOPp->sel_bit))
                                ? ((1U & (IData)(vlTOPp->sel_bit))
                                    ? (vlTOPp->data_out1 
                                       & vlTOPp->data_out2)
                                    : (vlTOPp->data_out1 
                                       | vlTOPp->data_out2))
                                : ((1U & (IData)(vlTOPp->sel_bit))
                                    ? (vlTOPp->data_out1 
                                       >> (0x1fU & vlTOPp->data_out2))
                                    : (vlTOPp->data_out1 
                                       ^ vlTOPp->data_out2)))
                            : ((2U & (IData)(vlTOPp->sel_bit))
                                ? ((1U & (IData)(vlTOPp->sel_bit))
                                    ? ((vlTOPp->data_out1 
                                        < vlTOPp->data_out2)
                                        ? 1U : 0U) : 
                                   ((vlTOPp->data_out1 
                                     < vlTOPp->data_out2)
                                     ? 1U : 0U)) : 
                               ((1U & (IData)(vlTOPp->sel_bit))
                                 ? (vlTOPp->data_out1 
                                    << (0x1fU & vlTOPp->data_out2))
                                 : (vlTOPp->data_out1 
                                    + vlTOPp->data_out2)))));
    vlTOPp->output_data_forstore = ((0U == (IData)(vlTOPp->sel_bit))
                                     ? vlTOPp->datapath__DOT__data_out3
                                     : ((2U == (IData)(vlTOPp->sel_bit))
                                         ? (0xffU & vlTOPp->datapath__DOT__data_out3)
                                         : ((4U == (IData)(vlTOPp->sel_bit))
                                             ? (0xffffU 
                                                & vlTOPp->datapath__DOT__data_out3)
                                             : 0U)));
    vlTOPp->load_result = ((IData)(vlTOPp->load_enb)
                            ? ((IData)(vlTOPp->lb) ? 
                               ((0xffffff00U & ((- (IData)(
                                                           (1U 
                                                            & (vlTOPp->datapath__DOT__dmem__DOT__memory
                                                               [
                                                               (0xfffU 
                                                                & vlTOPp->alu_out)] 
                                                               >> 7U)))) 
                                                << 8U)) 
                                | vlTOPp->datapath__DOT__dmem__DOT__memory
                                [(0xfffU & vlTOPp->alu_out)])
                                : ((IData)(vlTOPp->lh)
                                    ? ((0xffff0000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->datapath__DOT__dmem__DOT__memory
                                                          [
                                                          (0xfffU 
                                                           & ((IData)(1U) 
                                                              + vlTOPp->alu_out))] 
                                                          >> 7U)))) 
                                           << 0x10U)) 
                                       | ((vlTOPp->datapath__DOT__dmem__DOT__memory
                                           [(0xfffU 
                                             & ((IData)(1U) 
                                                + vlTOPp->alu_out))] 
                                           << 8U) | 
                                          vlTOPp->datapath__DOT__dmem__DOT__memory
                                          [(0xfffU 
                                            & vlTOPp->alu_out)]))
                                    : ((IData)(vlTOPp->lw)
                                        ? ((vlTOPp->datapath__DOT__dmem__DOT__memory
                                            [(0xfffU 
                                              & ((IData)(3U) 
                                                 + vlTOPp->alu_out))] 
                                            << 0x18U) 
                                           | ((vlTOPp->datapath__DOT__dmem__DOT__memory
                                               [(0xfffU 
                                                 & ((IData)(2U) 
                                                    + vlTOPp->alu_out))] 
                                               << 0x10U) 
                                              | ((vlTOPp->datapath__DOT__dmem__DOT__memory
                                                  [
                                                  (0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlTOPp->alu_out))] 
                                                  << 8U) 
                                                 | vlTOPp->datapath__DOT__dmem__DOT__memory
                                                 [(0xfffU 
                                                   & vlTOPp->alu_out)])))
                                        : ((IData)(vlTOPp->lbu)
                                            ? vlTOPp->datapath__DOT__dmem__DOT__memory
                                           [(0xfffU 
                                             & vlTOPp->alu_out)]
                                            : ((IData)(vlTOPp->lhu)
                                                ? (
                                                   (vlTOPp->datapath__DOT__dmem__DOT__memory
                                                    [
                                                    (0xfffU 
                                                     & ((IData)(1U) 
                                                        + vlTOPp->alu_out))] 
                                                    << 8U) 
                                                   | vlTOPp->datapath__DOT__dmem__DOT__memory
                                                   [
                                                   (0xfffU 
                                                    & vlTOPp->alu_out)])
                                                : 0U)))))
                            : 0U);
    vlTOPp->reg_input = ((4U & (IData)(vlTOPp->input_to_mux))
                          ? ((2U & (IData)(vlTOPp->input_to_mux))
                              ? 0U : ((1U & (IData)(vlTOPp->input_to_mux))
                                       ? 0U : vlTOPp->imm_out))
                          : ((2U & (IData)(vlTOPp->input_to_mux))
                              ? ((1U & (IData)(vlTOPp->input_to_mux))
                                  ? vlTOPp->pc_plus_imm_for_auipc
                                  : vlTOPp->pc_plus_4)
                              : ((1U & (IData)(vlTOPp->input_to_mux))
                                  ? vlTOPp->load_result
                                  : vlTOPp->alu_out)));
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__fetch__02Eclk = vlTOPp->fetch__02Eclk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
    vlTOPp->__Vclklast__TOP__datapath__02Eclk = vlTOPp->datapath__02Eclk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    fetch__02Eclk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    datapath__02Eclk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    instruction = VL_RAND_RESET_I(32);
    rs1 = VL_RAND_RESET_I(5);
    rs2 = VL_RAND_RESET_I(5);
    rdi = VL_RAND_RESET_I(5);
    reg_input = VL_RAND_RESET_I(32);
    load_result = VL_RAND_RESET_I(32);
    pc_plus_4 = VL_RAND_RESET_I(32);
    pc_plus_imm = VL_RAND_RESET_I(32);
    imm_for_b_type = VL_RAND_RESET_I(32);
    data_out1 = VL_RAND_RESET_I(32);
    data_out2 = VL_RAND_RESET_I(32);
    imm_out = VL_RAND_RESET_I(32);
    sel_bit = VL_RAND_RESET_I(4);
    wenb = VL_RAND_RESET_I(1);
    rs2_imm_sel = VL_RAND_RESET_I(1);
    jal_enb = VL_RAND_RESET_I(1);
    load_enb = VL_RAND_RESET_I(1);
    branch_enb = VL_RAND_RESET_I(1);
    auipc_wenb = VL_RAND_RESET_I(1);
    lui_enb = VL_RAND_RESET_I(1);
    branch_taken = VL_RAND_RESET_I(1);
    enable = VL_RAND_RESET_I(1);
    select = VL_RAND_RESET_I(1);
    pc_write = VL_RAND_RESET_I(1);
    sel_bit_mux = VL_RAND_RESET_I(2);
    inp = VL_RAND_RESET_I(5);
    alu_out = VL_RAND_RESET_I(32);
    output_data_forstore = VL_RAND_RESET_I(32);
    pc_plus_imm_for_auipc = VL_RAND_RESET_I(32);
    input_to_mux = VL_RAND_RESET_I(3);
    sb = VL_RAND_RESET_I(1);
    sh = VL_RAND_RESET_I(1);
    sw = VL_RAND_RESET_I(1);
    lb = VL_RAND_RESET_I(1);
    lh = VL_RAND_RESET_I(1);
    lw = VL_RAND_RESET_I(1);
    lbu = VL_RAND_RESET_I(1);
    lhu = VL_RAND_RESET_I(1);
    inst = VL_RAND_RESET_I(32);
    addr = VL_RAND_RESET_I(1);
    sub = VL_RAND_RESET_I(1);
    sllr = VL_RAND_RESET_I(1);
    sltr = VL_RAND_RESET_I(1);
    sltur = VL_RAND_RESET_I(1);
    xorr = VL_RAND_RESET_I(1);
    srlr = VL_RAND_RESET_I(1);
    srar = VL_RAND_RESET_I(1);
    orr = VL_RAND_RESET_I(1);
    andr = VL_RAND_RESET_I(1);
    addi = VL_RAND_RESET_I(1);
    slli = VL_RAND_RESET_I(1);
    slti = VL_RAND_RESET_I(1);
    sltui = VL_RAND_RESET_I(1);
    xori = VL_RAND_RESET_I(1);
    srli = VL_RAND_RESET_I(1);
    srai = VL_RAND_RESET_I(1);
    ori = VL_RAND_RESET_I(1);
    andi = VL_RAND_RESET_I(1);
    in_to_pr = VL_RAND_RESET_I(1);
    jal = VL_RAND_RESET_I(1);
    jalr = VL_RAND_RESET_I(1);
    beq = VL_RAND_RESET_I(1);
    bne = VL_RAND_RESET_I(1);
    blt = VL_RAND_RESET_I(1);
    bge = VL_RAND_RESET_I(1);
    bltu = VL_RAND_RESET_I(1);
    bgeu = VL_RAND_RESET_I(1);
    add = VL_RAND_RESET_I(1);
    sll = VL_RAND_RESET_I(1);
    slt = VL_RAND_RESET_I(1);
    sltu = VL_RAND_RESET_I(1);
    xorrr = VL_RAND_RESET_I(1);
    srl = VL_RAND_RESET_I(1);
    sra = VL_RAND_RESET_I(1);
    orrr = VL_RAND_RESET_I(1);
    andd = VL_RAND_RESET_I(1);
    out0 = VL_RAND_RESET_I(1);
    out1 = VL_RAND_RESET_I(1);
    out2 = VL_RAND_RESET_I(1);
    out3 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            fetch__DOT__IM__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    datapath__DOT__data_out3 = VL_RAND_RESET_I(32);
    datapath__DOT__imm = VL_RAND_RESET_I(32);
    datapath__DOT__priority_out = VL_RAND_RESET_I(1);
    datapath__DOT__pc_out = VL_RAND_RESET_I(32);
    datapath__DOT__pc_next = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            datapath__DOT__imem__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            datapath__DOT__reg_file__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
            datapath__DOT__dmem__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vtableidx1 = 0;
    __Vtablechg1[0] = 0U;
    __Vtablechg1[1] = 1U;
    __Vtablechg1[2] = 1U;
    __Vtablechg1[3] = 1U;
    __Vtablechg1[4] = 1U;
    __Vtablechg1[5] = 1U;
    __Vtablechg1[6] = 1U;
    __Vtablechg1[7] = 1U;
    __Vtablechg1[8] = 1U;
    __Vtablechg1[9] = 1U;
    __Vtablechg1[10] = 1U;
    __Vtablechg1[11] = 1U;
    __Vtablechg1[12] = 1U;
    __Vtablechg1[13] = 1U;
    __Vtablechg1[14] = 1U;
    __Vtablechg1[15] = 1U;
    __Vtable1_sel_bit_mux[0] = 0U;
    __Vtable1_sel_bit_mux[1] = 3U;
    __Vtable1_sel_bit_mux[2] = 2U;
    __Vtable1_sel_bit_mux[3] = 3U;
    __Vtable1_sel_bit_mux[4] = 1U;
    __Vtable1_sel_bit_mux[5] = 3U;
    __Vtable1_sel_bit_mux[6] = 2U;
    __Vtable1_sel_bit_mux[7] = 3U;
    __Vtable1_sel_bit_mux[8] = 0U;
    __Vtable1_sel_bit_mux[9] = 3U;
    __Vtable1_sel_bit_mux[10] = 2U;
    __Vtable1_sel_bit_mux[11] = 3U;
    __Vtable1_sel_bit_mux[12] = 1U;
    __Vtable1_sel_bit_mux[13] = 3U;
    __Vtable1_sel_bit_mux[14] = 2U;
    __Vtable1_sel_bit_mux[15] = 3U;
    __Vtable2_input_to_mux[0] = 0U;
    __Vtable2_input_to_mux[1] = 0U;
    __Vtable2_input_to_mux[2] = 1U;
    __Vtable2_input_to_mux[3] = 1U;
    __Vtable2_input_to_mux[4] = 2U;
    __Vtable2_input_to_mux[5] = 2U;
    __Vtable2_input_to_mux[6] = 2U;
    __Vtable2_input_to_mux[7] = 2U;
    __Vtable2_input_to_mux[8] = 3U;
    __Vtable2_input_to_mux[9] = 3U;
    __Vtable2_input_to_mux[10] = 3U;
    __Vtable2_input_to_mux[11] = 3U;
    __Vtable2_input_to_mux[12] = 3U;
    __Vtable2_input_to_mux[13] = 3U;
    __Vtable2_input_to_mux[14] = 3U;
    __Vtable2_input_to_mux[15] = 3U;
    __Vtable2_input_to_mux[16] = 4U;
    __Vtable2_input_to_mux[17] = 4U;
    __Vtable2_input_to_mux[18] = 4U;
    __Vtable2_input_to_mux[19] = 4U;
    __Vtable2_input_to_mux[20] = 4U;
    __Vtable2_input_to_mux[21] = 4U;
    __Vtable2_input_to_mux[22] = 4U;
    __Vtable2_input_to_mux[23] = 4U;
    __Vtable2_input_to_mux[24] = 4U;
    __Vtable2_input_to_mux[25] = 4U;
    __Vtable2_input_to_mux[26] = 4U;
    __Vtable2_input_to_mux[27] = 4U;
    __Vtable2_input_to_mux[28] = 4U;
    __Vtable2_input_to_mux[29] = 4U;
    __Vtable2_input_to_mux[30] = 4U;
    __Vtable2_input_to_mux[31] = 4U;
    __Vchglast__TOP__reg_input = VL_RAND_RESET_I(32);
}
