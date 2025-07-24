#include "spike_main.h"





spike_device::spike_device() : sim(nullptr), buffer(), buffer_data()
{
    srcfilename=new char[128];
    logfilename=new char[128];
    sim = nullptr;
    srcfilename = nullptr;
    logfilename = nullptr;
}