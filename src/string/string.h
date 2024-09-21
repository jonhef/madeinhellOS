struct string {
    char* data;
    unsigned long long size;
    unsigned long long capacity;
};

void string_init_char_size(struct string* s, char* data, unsigned int size);
void string_init_char(struct string* s, char* data);
void string_init(struct string* s);

void string_print(struct string s);
void string_println(struct string s);

void string_append_char(struct string* s, char data);
void string_append_chardata(struct string* s, char* data, unsigned int size);
void string_append_string(struct string* s, struct string s2);

char string_at(struct string s, unsigned int index);
struct string string_at_string(struct string s, unsigned int index, unsigned int size);

#define string_substr(s, start, size) string_at(s, start, size)
#define string_substr1(s, start, end) string_at(s, start, (end - start))

unsigned int string_length(struct string s);
unsigned int string_length_char(char* data);

void string_copy(struct string s1, struct string* s2);
void string_delete(struct string* xs);
