#pragma once
#include <cstdint>
#include <riscv/cfg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <queue>


#include "cfg.h"
#include "sim.h"
#include "mmu.h"
#include "remote_bitbang.h"
#include "cachesim.h"
#include "extension.h"
#include <dlfcn.h>
#include <fesvr/option_parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <memory>
#include <fstream>

struct meta_data {
    uint64_t kernel_id;
    uint64_t kernel_size[3];

};


class spike_device {
    public:
    spike_device();
    ~spike_device();

    int free_local_mem();
    int free_local_mem(uint64_t paddr);
    int free_local_mem(uint64_t paddr, uint64_t size);
    int copy_to_dev(uint64_t dev_maddr, uint64_t size,const void* data);
    int copy_from_dev(uint64_t dev_maddr, uint64_t size,void* data);
    int run(meta_data* knl_data,uint64_t knl_start_pc);
    int set_filename(const char* filename,const char* logname=nullptr);

private:
    sim_t * sim;
    std::vector<mem_cfg_t> buffer;
    std::vector<std::pair<reg_t, mem_t*>> buffer_data;
    std::vector<mem_cfg_t> const_buffer;
    std::vector<std::pair<reg_t, mem_t*>> const_buffer_data;
    char* srcfilename;
    char* logfilename;
};