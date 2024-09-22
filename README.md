# madeinhellOS
## Common.h
Contains types(u8, u16, u32, u64, s8, s16, s32, s64, bool)
- `memcpy(u8 *src, u8 *dest, u32 bytes)` - copies u8 data from one memory location to another
## zlib
Basic open source zlib library written by Apple inc.
## string/string.h
Basic string library realized by me specially for madeinhellOS
- `string_init_char_size(struct string* s, char* data, unsigned int size)` - initializes string with char* data and size
- `string_init_char(struct string* s, char* data)` - initializes string with char* data(it must contain \0 at the end of the string)
- `string_init(struct string* s)` - initializes string with empty data
- `string_print(struct string s)` - prints string
- `string_println(struct string s)` - prints string with newline
- `string_append_char(struct string* s, char data)` - appends char to string
- `string_append_chardata(struct string* s, char* data, unsigned int size)` - appends char* data to string
- `string_append_string(struct string* s, struct string s2)` - appends string to string
- `string_at(struct string s, unsigned int index)` - returns char at index
- `string_at_string(struct string s, unsigned int index, unsigned int size)` - returns string at index(like a substring)
- `string_length(struct string s)` - returns string length(it must contain \0 at the end of the string)
- `string_length_char(char* data)` - returns string length(it must contain \0 at the end of the string)
- `string_copy(struct string s1, struct string* s2)` - copies string s1 to string s2
- `string_delete(struct string* xs)` - deletes string(deallocate memory from data, and set data, size, capacity to NULL)
- `string_substr(s, start, size)` - returns string from start to start+size
- `string_substr1(s, start, end)` - returns string from start to end
## file
Contains file creation, file opening, file reading, file writing, file closing, and file deleting functions in file.h also contains assembler realizations for it
- `fopen(char* filename)` - opens file
- `fwrite(int descriptor, char* data, size_t size)` - writes data to file
- `fread(int descriptor, char* buffer, size_t size)` - reads data from file
- `fclose(int descriptor)` - closes file
- `CreateFile(file* f)` - creates file
- `CreateFile1(file* f)` - creates file(without deleting old file if exists)
- `mkdir(char* folder)` - creates folder
- `rmdir(char* folder)` - deletes folder
- `SetCurFolder(char* folder)` - sets current folder
- `GetCurFolder(char* folder)` - gets current folder
- `file` - type using to work with files
## kernel/memory.h
- `get_memory_size()` - returns total memory size in KiB
- `struct ptr` - default type(for madeinhellOS) for memory allocation(contains pointer to start of allocated memory and size of allocated memory in bytes)
- `malloc(unsigned long long size)` - allocates memory and returns struct ptr
- `free(struct ptr* ptr)` - deallocates memory
- `realloc(struct ptr* ptr, unsigned long long size)` - reallocates memory
**Please note that size of allocated memory is always multiple of default_memory_block_size(4096 bytes now)**
## drivers/lowlevel_io.h
- `port_byte_in(unsigned short port)` - reads byte from port
- `port_byte_out(unsigned short port, unsigned char data)` - writes byte to port
- `port_word_in(unsigned short port)` - reads word(2 bytes) from port
- `port_word_out(unsigned short port, unsigned short data)` - writes word(2 bytes) to port
## drivers/screen.h
- `kprint(u8 *str)` - prints string to screen(string must contain \0 at the end of the string)
- `putchar(u8 character, u8 attribute_byte)` - prints character to screen
- `clear_screen()` - clears screen
- `write(u8 character, u8 attribute_byte, u16 offset)` - prints character to screen with vga offset
- `scroll_line()` - scrolls screen line
- `get_cursor()` - returns cursor position
- `set_cursor(u16 pos)` - sets cursor position
## drivers/keyboard.h
- `get_key()` - returns scancode of pressed key
Also it contains all scancodes of keyboard in format KR_<key> for released keys and KP_<key> for pressed keys
Example: `KR_RIGHT_CTRL` for released right control key and `KP_RIGHT_CTRL` for pressed right control key