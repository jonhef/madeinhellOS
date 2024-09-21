// memory.h
#ifndef MEMORY_H
#define MEMORY_H

extern unsigned long get_memory_size(void); // Объявляем функцию из ассемблера

struct ptr {
    void* ptr;
    unsigned long long size;
};

struct ptr* malloc(unsigned long long size);
void free(struct ptr* ptr);
struct ptr* realloc(struct ptr* ptr, unsigned long long size);

#endif // MEMORY_H