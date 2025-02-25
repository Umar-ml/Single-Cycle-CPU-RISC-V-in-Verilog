#include <verilated.h>
#include "Vdatapath.h"
#include <iostream>
#include <fstream>

#define SIM_TIME 100 // Total simulation time in cycles

Vdatapath* datapath; // Pointer to the DUT
vluint64_t main_time = 0; // Simulation time

// Clock generation function
void tick() {
    datapath->clk = 0;
    datapath->eval();
    main_time += 5;

    datapath->clk = 1;
    datapath->eval();
    main_time += 5;
}

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    datapath = new Vdatapath;

    // Initialize signals
    datapath->reset = 1;
    datapath->enable = 0;
    datapath->pc_write = 0;

    // Apply reset
    tick();
    datapath->reset = 0;
    datapath->pc_write = 1;

    // Open VCD waveform file
    Verilated::traceEverOn(true);

    std::ofstream vcdFile("datapath_tb.vcd");
    if (!vcdFile.is_open()) {
        std::cerr << "Failed to open VCD file!" << std::endl;
        return 1;
    }

    // Simulation loop
    for (int i = 0; i < SIM_TIME; i++) {
        tick();
        
        // Print signals for debugging
        printf("Time: %d ns | instruction: 0x%x | rs1: %d | rs2: %d | rdi: %d | ALU Out: 0x%x | Load Result: %d | Wenb: %d | Branch Taken: %d\n",
       main_time, datapath->instruction, (int)datapath->rs1, (int)datapath->rs2, (int)datapath->rdi, 
       datapath->alu_out, datapath->load_result, (int)datapath->wenb, (int)datapath->branch_taken);
		
    }

    // Cleanup
    delete datapath;
    return 0;
}

