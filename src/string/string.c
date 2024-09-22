#include "./string.h"
#include "../common.h"
#include "../drivers/screen.h"
#include "../kernel/memory.h"

void string_init_char_size(struct string* s, char* data, unsigned int size)
{
    struct ptr* new_data = malloc(size + 1);
    s->data = new_data->ptr;
    s->capacity = new_data->size;
    s->size = size;
    for (unsigned int i = 0; i < size; i++)
    {
        s->data[i] = data[i];
    }
    s->data[size] = '\0';
    return;
}
void string_init_char(struct string* s, char* data)
{
    unsigned int size = string_length_char(data);
    struct ptr* new_data = malloc(size + 1);
    s->data = new_data->ptr;
    s->capacity = new_data->size;
    for (unsigned int i = 0; i < size; i++)
    {
        s->data[i] = data[i];
    }
    s->size = size;
    s->data[size] = '\0';
    return;
}
void string_init(struct string* s)
{
    struct ptr* new_data = malloc(1);
    s->data = new_data->ptr;
    s->capacity = new_data->size;
    s->data[0] = '\0';
    s->size = 0;
    return;
}

void string_print(struct string s)
{
    for (unsigned int i = 0; i < s.size; i++)
    {
        putchar(s.data[i], WHITE_ON_BLACK);
    }
    return;
}
void string_println(struct string s)
{
    for (unsigned int i = 0; i < s.size; i++)
    {
        putchar(s.data[i], WHITE_ON_BLACK);
    }
    putchar('\n', WHITE_ON_BLACK);
    return;
}

void string_append_char(struct string* s, char data)
{
    struct ptr* new_data = malloc(s->size + 1 + 1);
    struct ptr* c;
    c->ptr = s->data;
    c->size = s->size;
    s->data = new_data->ptr;
    s->capacity = new_data->size;
    for (unsigned int i = 0; i < s->size; i++)
    {
        s->data[i] = s->data[i];
    }
    free(c);
    s->data[s->size] = data;
    s->data[s->size + 1] = '\0';
    ++s->size;
    return;
}
void string_append_chardata(struct string* s, char* data, unsigned int size)
{
    struct ptr* new_data = malloc(size + 1);
    struct ptr* c;
    c->ptr = s->data;
    c->size = s->size;
    s->data = new_data->ptr;
    s->capacity = new_data->size;
    for (unsigned long long i = 0; i < s->size; ++i)
    {
        s->data[i] = ((char*)c->ptr)[i];
    }
    free(c);
    for (unsigned long long i = s->size; i < s->size + size; ++i)
    {
        s->data[i] = data[i - s->size];
    }
    s->data[size] = '\0';
    s->size = size;
    return;
}
void string_append_string(struct string* s, struct string s2)
{
    struct ptr* c;
    c->ptr = s->data;
    c->size = s->size;
    struct ptr* new_data = realloc(c, s->size + s2.size + 1);
    s->data = new_data->ptr;
    s->capacity = new_data->size;
    for (unsigned long long i = 0; i < s->size; ++i)
    {
        s->data[i] = ((char*)c->ptr)[i];
    }
    for (unsigned long long i = s->size; i < s->size + s2.size; ++i)
    {
        s->data[i] = s2.data[i - s->size];
    }
    s->data[s->size + s2.size] = '\0';
    s->size = s->size + s2.size;
    return;
}

char string_at(struct string s, unsigned int index)
{
    if (index >= s.size)
    {
        return '\0';
    }
    return s.data[index];
}
struct string string_at_string(struct string s, unsigned int index, unsigned int size)
{
    struct string res;
    struct ptr* ptr = malloc(size + 1);
    res.data = ptr->ptr;
    res.capacity = ptr->size;
    res.size = size;
    for (unsigned int i = 0; i < size; i++)
    {
        res.data[i] = s.data[index + i];
    }
    return res;
}

unsigned int string_length(struct string s)
{
    return s.size;
}
unsigned int string_length_char(char* data)
{
    unsigned int size = 0;
    while (data[size] != '\0')
    {
        size++;
    }
    return size;
}

void string_copy(struct string s1, struct string* s2)
{
    struct ptr* ptr = malloc(s1.size + 1);
    s2->data = ptr->ptr;
    s2->capacity = ptr->size;
    s2->size = s1.size;
    for (unsigned int i = 0; i < s1.size; i++)
    {
        s2->data[i] = s1.data[i];
    }
    return;
}
void string_delete(struct string* xs)
{
    struct ptr* ptr;
    ptr->ptr = xs->data;
    ptr->size = xs->size;
    free(ptr);
    xs->data = NULL;
    xs->size = NULL;
    xs->capacity = NULL;
    return;
}