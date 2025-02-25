// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 32, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 32, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->load_enb = (((((IData)(vlTOPp->lb) | (IData)(vlTOPp->lh)) 
                          | (IData)(vlTOPp->lw)) | (IData)(vlTOPp->lbu)) 
                        | (IData)(vlTOPp->lhu));
    vlTOPp->slt = ((IData)(vlTOPp->sltr) | (IData)(vlTOPp->slti));
    vlTOPp->sll = ((IData)(vlTOPp->sllr) | (IData)(vlTOPp->slli));
    vlTOPp->xorrr = ((IData)(vlTOPp->xorr) | (IData)(vlTOPp->xori));
    vlTOPp->sltu = ((IData)(vlTOPp->sltur) | (IData)(vlTOPp->sltui));
    vlTOPp->orrr = ((IData)(vlTOPp->orr) | (IData)(vlTOPp->ori));
    vlTOPp->srl = ((IData)(vlTOPp->srlr) | (IData)(vlTOPp->srli));
    vlTOPp->sra = ((IData)(vlTOPp->srar) | (IData)(vlTOPp->srai));
    vlTOPp->andd = ((IData)(vlTOPp->andr) | (IData)(vlTOPp->andi));
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
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__datapath__DOT__reg_file__DOT__registers__v0;
    CData/*4:0*/ __Vdlyvdim0__datapath__DOT__reg_file__DOT__registers__v32;
    CData/*0:0*/ __Vdlyvset__datapath__DOT__reg_file__DOT__registers__v32;
    IData/*31:0*/ __Vdlyvval__datapath__DOT__reg_file__DOT__registers__v32;
    // Body
    __Vdlyvset__datapath__DOT__reg_file__DOT__registers__v0 = 0U;
    __Vdlyvset__datapath__DOT__reg_file__DOT__registers__v32 = 0U;
    if (vlTOPp->reset) {
        vlTOPp->datapath__DOT__pc_out = 0U;
    } else {
        if (vlTOPp->pc_write) {
            vlTOPp->datapath__DOT__pc_out = vlTOPp->datapath__DOT__pc_next;
        }
    }
    if (vlTOPp->reset) {
        __Vdlyvset__datapath__DOT__reg_file__DOT__registers__v0 = 1U;
    } else {
        if (((IData)(vlTOPp->enable) & (0U != (IData)(vlTOPp->rdi)))) {
            __Vdlyvval__datapath__DOT__reg_file__DOT__registers__v32 
                = vlTOPp->reg_input;
            __Vdlyvset__datapath__DOT__reg_file__DOT__registers__v32 = 1U;
            __Vdlyvdim0__datapath__DOT__reg_file__DOT__registers__v32 
                = vlTOPp->rdi;
        }
    }
    if (__Vdlyvset__datapath__DOT__reg_file__DOT__registers__v0) {
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[1U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[2U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[3U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[4U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[5U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[6U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[7U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[8U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[9U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0xaU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0xbU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0xcU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0xdU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0xeU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0xfU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x10U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x11U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x12U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x13U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x14U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x15U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x16U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x17U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x18U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x19U] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x1aU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x1bU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x1cU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x1dU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x1eU] = 0U;
        vlTOPp->datapath__DOT__reg_file__DOT__registers[0x1fU] = 0U;
    }
    if (__Vdlyvset__datapath__DOT__reg_file__DOT__registers__v32) {
        vlTOPp->datapath__DOT__reg_file__DOT__registers[__Vdlyvdim0__datapath__DOT__reg_file__DOT__registers__v32] 
            = __Vdlyvval__datapath__DOT__reg_file__DOT__registers__v32;
    }
    vlTOPp->inst = vlTOPp->datapath__DOT__imem__DOT__memory
        [(0xffU & (vlTOPp->datapath__DOT__pc_out >> 2U))];
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__datapath__DOT__dmem__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__datapath__DOT__dmem__DOT__memory__v0;
    CData/*7:0*/ __Vdlyvval__datapath__DOT__dmem__DOT__memory__v1;
    CData/*0:0*/ __Vdlyvset__datapath__DOT__dmem__DOT__memory__v1;
    CData/*7:0*/ __Vdlyvval__datapath__DOT__dmem__DOT__memory__v2;
    CData/*7:0*/ __Vdlyvval__datapath__DOT__dmem__DOT__memory__v3;
    CData/*0:0*/ __Vdlyvset__datapath__DOT__dmem__DOT__memory__v3;
    CData/*7:0*/ __Vdlyvval__datapath__DOT__dmem__DOT__memory__v4;
    CData/*7:0*/ __Vdlyvval__datapath__DOT__dmem__DOT__memory__v5;
    CData/*7:0*/ __Vdlyvval__datapath__DOT__dmem__DOT__memory__v6;
    SData/*11:0*/ __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v0;
    SData/*11:0*/ __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v1;
    SData/*11:0*/ __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v2;
    SData/*11:0*/ __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v3;
    SData/*11:0*/ __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v4;
    SData/*11:0*/ __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v5;
    SData/*11:0*/ __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v6;
    // Body
    __Vdlyvset__datapath__DOT__dmem__DOT__memory__v0 = 0U;
    __Vdlyvset__datapath__DOT__dmem__DOT__memory__v1 = 0U;
    __Vdlyvset__datapath__DOT__dmem__DOT__memory__v3 = 0U;
    if (vlTOPp->sb) {
        __Vdlyvval__datapath__DOT__dmem__DOT__memory__v0 
            = (0xffU & vlTOPp->output_data_forstore);
        __Vdlyvset__datapath__DOT__dmem__DOT__memory__v0 = 1U;
        __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v0 
            = (0xfffU & vlTOPp->alu_out);
    } else {
        if (vlTOPp->sh) {
            __Vdlyvval__datapath__DOT__dmem__DOT__memory__v1 
                = (0xffU & vlTOPp->output_data_forstore);
            __Vdlyvset__datapath__DOT__dmem__DOT__memory__v1 = 1U;
            __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v1 
                = (0xfffU & vlTOPp->alu_out);
            __Vdlyvval__datapath__DOT__dmem__DOT__memory__v2 
                = (0xffU & (vlTOPp->output_data_forstore 
                            >> 8U));
            __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v2 
                = (0xfffU & ((IData)(1U) + vlTOPp->alu_out));
        } else {
            if (vlTOPp->sw) {
                __Vdlyvval__datapath__DOT__dmem__DOT__memory__v3 
                    = (0xffU & vlTOPp->output_data_forstore);
                __Vdlyvset__datapath__DOT__dmem__DOT__memory__v3 = 1U;
                __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v3 
                    = (0xfffU & vlTOPp->alu_out);
                __Vdlyvval__datapath__DOT__dmem__DOT__memory__v4 
                    = (0xffU & (vlTOPp->output_data_forstore 
                                >> 8U));
                __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v4 
                    = (0xfffU & ((IData)(1U) + vlTOPp->alu_out));
                __Vdlyvval__datapath__DOT__dmem__DOT__memory__v5 
                    = (0xffU & (vlTOPp->output_data_forstore 
                                >> 0x10U));
                __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v5 
                    = (0xfffU & ((IData)(2U) + vlTOPp->alu_out));
                __Vdlyvval__datapath__DOT__dmem__DOT__memory__v6 
                    = (0xffU & (vlTOPp->output_data_forstore 
                                >> 0x18U));
                __Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v6 
                    = (0xfffU & ((IData)(3U) + vlTOPp->alu_out));
            }
        }
    }
    if (__Vdlyvset__datapath__DOT__dmem__DOT__memory__v0) {
        vlTOPp->datapath__DOT__dmem__DOT__memory[__Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v0] 
            = __Vdlyvval__datapath__DOT__dmem__DOT__memory__v0;
    }
    if (__Vdlyvset__datapath__DOT__dmem__DOT__memory__v1) {
        vlTOPp->datapath__DOT__dmem__DOT__memory[__Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v1] 
            = __Vdlyvval__datapath__DOT__dmem__DOT__memory__v1;
        vlTOPp->datapath__DOT__dmem__DOT__memory[__Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v2] 
            = __Vdlyvval__datapath__DOT__dmem__DOT__memory__v2;
    }
    if (__Vdlyvset__datapath__DOT__dmem__DOT__memory__v3) {
        vlTOPp->datapath__DOT__dmem__DOT__memory[__Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v3] 
            = __Vdlyvval__datapath__DOT__dmem__DOT__memory__v3;
        vlTOPp->datapath__DOT__dmem__DOT__memory[__Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v4] 
            = __Vdlyvval__datapath__DOT__dmem__DOT__memory__v4;
        vlTOPp->datapath__DOT__dmem__DOT__memory[__Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v5] 
            = __Vdlyvval__datapath__DOT__dmem__DOT__memory__v5;
        vlTOPp->datapath__DOT__dmem__DOT__memory[__Vdlyvdim0__datapath__DOT__dmem__DOT__memory__v6] 
            = __Vdlyvval__datapath__DOT__dmem__DOT__memory__v6;
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rdi = (0x1fU & (vlTOPp->instruction >> 7U));
    vlTOPp->pc_plus_imm_for_auipc = (vlTOPp->datapath__DOT__pc_out 
                                     + vlTOPp->imm_out);
    vlTOPp->data_out1 = ((0U == (IData)(vlTOPp->rs1))
                          ? 0U : vlTOPp->datapath__DOT__reg_file__DOT__registers
                         [vlTOPp->rs1]);
    vlTOPp->data_out2 = ((0U == (IData)(vlTOPp->rs2))
                          ? 0U : vlTOPp->datapath__DOT__reg_file__DOT__registers
                         [vlTOPp->rs2]);
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
    vlTOPp->datapath__DOT__data_out3 = ((IData)(vlTOPp->rs2_imm_sel)
                                         ? vlTOPp->imm_out
                                         : vlTOPp->data_out2);
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
    vlTOPp->output_data_forstore = ((0U == (IData)(vlTOPp->sel_bit))
                                     ? vlTOPp->datapath__DOT__data_out3
                                     : ((2U == (IData)(vlTOPp->sel_bit))
                                         ? (0xffU & vlTOPp->datapath__DOT__data_out3)
                                         : ((4U == (IData)(vlTOPp->sel_bit))
                                             ? (0xffffU 
                                                & vlTOPp->datapath__DOT__data_out3)
                                             : 0U)));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__4(vlSymsp);
    if ((((IData)(vlTOPp->datapath__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__datapath__02Eclk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->datapath__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__datapath__02Eclk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__fetch__02Eclk = vlTOPp->fetch__02Eclk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
    vlTOPp->__Vclklast__TOP__datapath__02Eclk = vlTOPp->datapath__02Eclk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->reg_input ^ vlTOPp->__Vchglast__TOP__reg_input));
    VL_DEBUG_IF( if(__req && ((vlTOPp->reg_input ^ vlTOPp->__Vchglast__TOP__reg_input))) VL_DBG_MSGF("        CHANGE: top.v:443: reg_input\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__reg_input = vlTOPp->reg_input;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((fetch__02Eclk & 0xfeU))) {
        Verilated::overWidthError("fetch.clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((datapath__02Eclk & 0xfeU))) {
        Verilated::overWidthError("datapath.clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
    if (VL_UNLIKELY((select & 0xfeU))) {
        Verilated::overWidthError("select");}
    if (VL_UNLIKELY((pc_write & 0xfeU))) {
        Verilated::overWidthError("pc_write");}
}
#endif  // VL_DEBUG
