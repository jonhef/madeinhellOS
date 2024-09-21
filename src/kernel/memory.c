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

struct ptr* malloc(unsigned long long size)
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
    struct ptr* ptr;
    ptr->ptr = res;
    ptr->size = size;
    if (iter_blocks == memory_blocks_end)
    {
        ptr->ptr = NULL;
        ptr->size = NULL;
        return ptr;
    }
    iter_blocks = (struct memory_block*)res;
    for (int i = 0; i < size / default_memory_block_size; ++i)
    {
        iter_blocks->is_used = true;
        ++iter_blocks;
    }
    return ptr;
}

void free(struct ptr* ptr)
{
    if (ptr->ptr == NULL)
    {
        return;
    }
    struct memory_block* iter_blocks = memory_blocks;
    for (;iter_blocks != memory_blocks_end;iter_blocks++)
    {
        if (iter_blocks->sector == (unsigned long long)(ptr->ptr))
        {
            for (int i = 0; i < ptr->size / default_memory_block_size; ++i)
            {
                iter_blocks->is_used = false;
                return;
            }
        }
    }
}

struct ptr* realloc(struct ptr* ptr, unsigned long long size)
{
    if (ptr->ptr == NULL)
    {
        return ptr;
    }
    if (ptr->size == size)
    {
        return ptr;
    }
    if (size % default_memory_block_size != 0)
    {
        size += default_memory_block_size - (size % default_memory_block_size);
    }
    if (ptr->size < size)
    {
        unsigned long long new_blocks = (size - ptr->size) / default_memory_block_size;
        for (int i = 0; i < new_blocks; ++i)
        {
            if ((memory_blocks + (unsigned long long)ptr->ptr/default_memory_block_size + i)->is_used == true)
            {
                return ptr;
            }
            else
            {
                (memory_blocks + (unsigned long long)ptr->ptr/default_memory_block_size + i)->is_used = true;
            }
        }
        return ptr;
    }
    if (ptr->size > size)
    {
        unsigned long long last_block = ptr->size / default_memory_block_size;
        for (int i = size / default_memory_block_size + 1; i != last_block; ++i)
        {
            (memory_blocks + ((unsigned long long)ptr->ptr)/default_memory_block_size + i)->is_used = false;
        }
        ptr->size = size;
        return ptr;
    }
}