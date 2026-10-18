// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fifo.h for the primary calling header

#include "Vtb_fifo__pch.h"
#include "Vtb_fifo__Syms.h"
#include "Vtb_fifo___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_fifo___024root___eval_initial__TOP__Vtiming__0(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string __Vtask_tb_fifo__DOT__fail__2__message;
    std::string __Vtask_tb_fifo__DOT__fail__3__message;
    std::string __Vtask_tb_fifo__DOT__fail__5__message;
    std::string __Vtask_tb_fifo__DOT__fail__8__message;
    std::string __Vtask_tb_fifo__DOT__fail__9__message;
    // Body
    VL_WRITEF_NX("TEST_START fifo_basic\n",0);
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    vlSelfRef.tb_fifo__DOT__rst_n = 1U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    if (VL_UNLIKELY((0U != vlSelfRef.tb_fifo__DOT__dut__DOT__count))) {
        __Vtask_tb_fifo__DOT__fail__2__message = std::string{"FIFO should be empty after reset"};
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__2__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    if (VL_UNLIKELY((4U == vlSelfRef.tb_fifo__DOT__dut__DOT__count))) {
        __Vtask_tb_fifo__DOT__fail__3__message = std::string{"FIFO should not be full after reset"};
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__3__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         42);
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__din = 0xaU;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         42);
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__din = 0x14U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         42);
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__din = 0x1eU;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         42);
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__din = 0x28U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         47);
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    if (VL_UNLIKELY((4U != vlSelfRef.tb_fifo__DOT__dut__DOT__count))) {
        __Vtask_tb_fifo__DOT__fail__5__message = std::string{"FIFO should be full after DEPTH writes"};
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__5__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         52);
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__din = 0xeeU;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         56);
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    if (VL_UNLIKELY((0xaU != (IData)(vlSelfRef.tb_fifo__DOT__dout)))) {
        __Vtask_tb_fifo__DOT__fail__8__message = VL_SFORMATF_N_NX("Expected 10, got %0#",0,
                                                                  8,
                                                                  vlSelfRef.tb_fifo__DOT__dout) ;
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__8__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    if (VL_UNLIKELY((0x14U != (IData)(vlSelfRef.tb_fifo__DOT__dout)))) {
        __Vtask_tb_fifo__DOT__fail__8__message = VL_SFORMATF_N_NX("Expected 20, got %0#",0,
                                                                  8,
                                                                  vlSelfRef.tb_fifo__DOT__dout) ;
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__8__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    if (VL_UNLIKELY((0x1eU != (IData)(vlSelfRef.tb_fifo__DOT__dout)))) {
        __Vtask_tb_fifo__DOT__fail__8__message = VL_SFORMATF_N_NX("Expected 30, got %0#",0,
                                                                  8,
                                                                  vlSelfRef.tb_fifo__DOT__dout) ;
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__8__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         22);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                         23);
    if (VL_UNLIKELY((0x28U != (IData)(vlSelfRef.tb_fifo__DOT__dout)))) {
        __Vtask_tb_fifo__DOT__fail__8__message = VL_SFORMATF_N_NX("Expected 40, got %0#",0,
                                                                  8,
                                                                  vlSelfRef.tb_fifo__DOT__dout) ;
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__8__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 
                                                         66);
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    if (VL_UNLIKELY((0U != vlSelfRef.tb_fifo__DOT__dut__DOT__count))) {
        __Vtask_tb_fifo__DOT__fail__9__message = std::string{"FIFO should be empty after reading all items"};
        VL_WRITEF_NX("FAIL: %@\n[%0t] %%Fatal: tb_fifo.sv:28: Assertion failed in %Ntb_fifo.fail\n",0,
                     -1,&(__Vtask_tb_fifo__DOT__fail__9__message),
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 28, "", false);
    }
    VL_WRITEF_NX("PASS: fifo_basic\n",0);
    VL_FINISH_MT("/home/mesul/projects/rtl-simulation-regression-analyzer/tb/tb_fifo.sv", 71, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fifo___024root___dump_triggers__act(Vtb_fifo___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_fifo___024root___eval_triggers__act(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.tb_fifo__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.tb_fifo__DOT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.set(3U, ((~ (IData)(vlSelfRef.tb_fifo__DOT__clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0 
        = vlSelfRef.tb_fifo__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__rst_n__0 
        = vlSelfRef.tb_fifo__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fifo___024root___dump_triggers__act(vlSelf);
    }
#endif
}
