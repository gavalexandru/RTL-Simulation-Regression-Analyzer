// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_fifo.h for the primary calling header

#ifndef VERILATED_VTB_FIFO___024ROOT_H_
#define VERILATED_VTB_FIFO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_fifo__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_fifo___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_fifo__DOT__clk;
    CData/*0:0*/ tb_fifo__DOT__rst_n;
    CData/*0:0*/ tb_fifo__DOT__wr_en;
    CData/*0:0*/ tb_fifo__DOT__rd_en;
    CData/*7:0*/ tb_fifo__DOT__din;
    CData/*7:0*/ tb_fifo__DOT__dout;
    CData/*0:0*/ tb_fifo__DOT__full;
    CData/*0:0*/ tb_fifo__DOT__empty;
    CData/*1:0*/ tb_fifo__DOT__dut__DOT__wr_ptr;
    CData/*1:0*/ tb_fifo__DOT__dut__DOT__rd_ptr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fifo__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_fifo__DOT__dut__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 4> tb_fifo__DOT__dut__DOT__mem;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h7211e072__0;
    VlTriggerScheduler __VtrigSched_h7211e033__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_fifo__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_fifo___024root(Vtb_fifo__Syms* symsp, const char* v__name);
    ~Vtb_fifo___024root();
    VL_UNCOPYABLE(Vtb_fifo___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
