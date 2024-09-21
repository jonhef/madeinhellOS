#include "memory.h"
#include "../common.h"

unsigned int default_memory_block_size = 4096 /* 4 KiB */;
unsigned int default_os_memory_size = 16*1024*1024;

struct memory_block {
    unsigned long long sector;
    bool is_used;
    //next block is default_memory_block_size+start, end is default_memory_block_size+start-1
};

//sizeof(unsigned long long) = 8
//size of memory_block = 8B
//size of memory_blocks = get_memory_size() / default_memory_block_size * memory_block_size
//first address of virtual memory
struct memory_block* memory_blocks = (struct memory_block*)(unsigned int)(16*1024*1024);
struct memory_block* memory_blocks_end;

void init_memory()
{
    #ifdef INIT_MEMORY
    throw "MEMORY IS INITIALIZED";
    #endif
    #define INIT_MEMORY
    unsigned long long memory_size = get_memory_size();
    unsigned long long memory_block_size = sizeof(struct memory_block);
    struct memory_block* memory_block = memory_blocks;
    memory_block->sector = (unsigned long long)(memory_blocks + ((memory_size*1024 - 16*1024*1024) / default_memory_block_size * memory_block_size));
    memory_block->is_used = false;
    memory_blocks_end = memory_blocks + ((memory_size*1024 - 16*1024*1024) / default_memory_block_size * memory_block_size);
    for (++memory_block; memory_block != memory_blocks_end; ++memory_block)
    {
        memory_block->sector = (memory_block - 1)->sector + default_memory_block_size;
        memory_block->is_used = false;
    }
}

void* malloc(unsigned long long size)
{
    #ifndef INIT_MEMORY
    throw "MEMORY IS NOT INITIALIZED";
    #endif
    if (size % default_memory_block_size != 0)
    {
        size += default_memory_block_size - (size % default_memory_block_size);
    }
    struct memory_block* iter_blocks = memory_blocks;
    unsigned long long size_of_block = 0;
    void* res = iter_blocks;
    for (;iter_blocks != memory_blocks_end;iter_blocks++)
    {
        if (iter_blocks->is_used == false)
        {
            size_of_block += iter_blocks->sector;
            if (size_of_block >= size)
            {
                break;
            }
        }
        else if (iter_blocks->is_used == true)
        {
            if (size_of_block >= size)
            {
                break;
            }
            size_of_block = 0;
            res = iter_blocks+1;
            continue;
        }
    }
    if (iter_blocks == memory_blocks_end)
        return NULL;
    iter_blocks = (struct memory_block*)res;
    for (int i = 0; i < size / default_memory_block_size; ++i)
    {
        iter_blocks->is_used = true;
        ++iter_blocks;
    }
    return res;
}

void free(void* ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    struct memory_block* iter_blocks = memory_blocks;
    for (;iter_blocks != memory_blocks_end;iter_blocks++)
    {
        if (iter_blocks->sector == (unsigned long long)ptr)
        {
            iter_blocks->is_used = false;
        }
    }
}