#include "include/vortex.h"
#include <iostream>


extern int vx_dev_open(vx_device_h* hdevice) {
    if (hdevice == NULL) {
        fprintf(stderr, "vx_dev_open: hdevice is NULL\n");
        return -1;
    }

    INFO << "Opening Vortex device..." << std::endl;
    //TODO: add spike_device implementation
    *hdevice = new spike_device();
    return 0;
}


// Close the device when all the operations are done
extern int vx_dev_close(vx_device_h hdevice) {
    if (hdevice == nullptr) {
        fprintf(stderr, "vx_dev_close: hdevice is NULL\n");
        return -1;
    }

    INFO << "Closing Vortex device..." << std::endl;
    auto* device = (spike_device*) hdevice;
    if (device) {
        delete device;
        hdevice = NULL;
    }
    return 0;
}

// return device configurations
extern int vx_dev_caps(vx_device_h hdevice, uint32_t caps_id, uint64_t *value) {
    return 0;
}

// allocate device memory and return address
extern int vx_mem_alloc(vx_device_h hdevice, uint64_t size, int flags, vx_buffer_h* hbuffer) {
    return -1;
}

// reserve memory address range
extern int vx_mem_reserve(vx_device_h hdevice, uint64_t address, uint64_t size, int flags, vx_buffer_h* hbuffer) {
    return -1;
}

// release device memory
extern int vx_mem_free(vx_device_h hbuffer) {
    return -1;
}

// // set device memory access rights
// extern int vx_mem_access(vx_buffer_h hbuffer, uint64_t offset, uint64_t size, int flags) {
//     return -1;
// }

// // return device memory address
// int vx_mem_address(vx_buffer_h hbuffer, uint64_t* address);

// // get device memory info
// int vx_mem_info(vx_device_h hdevice, uint64_t* mem_free, uint64_t* mem_used);

// Copy bytes from host to device memory
int vx_copy_to_dev(vx_device_h hdevice, void * dev_addr, void * src_addr, uint64_t size) {
    if (size <= 0) {
        fprintf(stderr, "vx_copy_to_dev: Invalid size %llu\n", size);
        return -1;
    }

    auto device = (spike_device*) hdevice;
    return device->copy_to_dev(dev_addr, size, src_addr);
}


// Copy bytes from device memory to host
int vx_copy_from_dev(vx_device_h hdevice, void * dev_vaddr, void * src_addr, uint64_t size) {
    if (size <= 0) {
        fprintf(stderr, "vx_copy_from_dev: Invalid size %llu\n", size);
        return -1;
    }

    auto device = (spike_device*) hdevice;
    return device->copy_from_dev(dev_vaddr, size, src_addr);
}

// Start device execution
int vx_start(vx_device_h hdevice, void* metaData, uint64_t taskID) {
    if (hdevice == NULL || metaData == NULL) {
        fprintf(stderr, "vx_start: Invalid arguments\n");
        return -1;
    }

    INFO << "Starting device execution..." << std::endl;
    auto device = (spike_device*) hdevice;
    auto kernel_data = (meta_data*) metaData;
    device->run(kernel_data, taskID);
    return 0;
}

// Wait for device ready with milliseconds timeout
int vx_ready_wait(vx_device_h hdevice, uint64_t timeout) {
    return 0;
}

// upload file to device
int vx_upload_kernel_file(vx_device_h hdevice, const char* filename, vx_buffer_h* hbuffer) {
    if (hdevice == NULL || filename == NULL || hbuffer == NULL) {
        fprintf(stderr, "vx_upload_kernel_file: Invalid arguments\n");
        return -1;
    }

    INFO << "Uploading kernel file: " << filename << std::endl;

    auto device = (spike_device*) hdevice;
    device->set_filename(filename);
    return 0;
}

