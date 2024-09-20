#include "./string.h"
#include "../common.h"
#include "../drivers/screen.h"

void string_init_char_size(struct string* s, char* data, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        s->data[i] = data[i];
    }
    s->size = size;
    s->data[size] = '\0';
    return;
}
void string_init_char(struct string* s, char* data)
{
    unsigned int size = string_length_char(data);
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
    char* new_data = (char*)malloc(s->size + 1);
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