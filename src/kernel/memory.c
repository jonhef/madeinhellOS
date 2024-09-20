#include "memory.h"

unsigned int default_memory_block_size = 4096 /* 4 KiB */;
unsigned int default_os_memory_size = 16*1024*1024;

struct memory_block {
    unsigned long long sector;
    //next block is default_memory_block_size+start, end is default_memory_block_size+start-1
};

//sizeof(unsigned long long) = 8
//size of memory_block = 8B
//size of memory_blocks = get_memory_size() / default_memory_block_size * memory_block_size
//first address of virtual memory
struct memory_block* memory_blocks = (struct memory_block*)(unsigned int)(16*1024*1024);

void init_memory()
{
    #ifdef INIT_MEMORY
    throw "MEMORY IS INITIALIZED";
    #endif
    #define INIT_MEMORY
    unsigned long long memory_size = get_memory_size();
    unsigned long long memory_block_size = sizeof(struct memory_block);
    for (; memory_blocks != memory_blocks + ((memory_size*1024 - 16*1024*1024) / default_memory_block_size * memory_block_size))
}

void* malloc(unsigned long long size)
{
    if (size % default_memory_block_size != 0)
    {
        size += default_memory_block_size - (size % default_memory_block_size);
    }
    struct memory_block* block = memory_blocks;
    unsigned long long size_of_block = 0;
    for (; )
}