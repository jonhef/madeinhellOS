//
// Created by d on 12.08.2023.
//
#include <string.h>

extern int __CreateFile(char[12]);
extern int __CloseFile(int);
extern int __CreateFileWithoutDelete(char[12]);
extern int __mkdir(char*);
extern int __rmdir(char*);
extern int __setcurrentfolder(char*);
extern char* __getcurrentfolder();
extern int __openfile(char*);
extern int __writefile(int, char*, size_t);
extern char* __readfile(int, size_t);

typedef enum { false, true } bool;
typedef file struct file
{
    char filename*;
    char extension*;
    char* data;
    size_t size;
};
void FileInit(file* f, char* filename, size_t filename_size, char* extension, size_t extension_size, char* data, size_t size)
{
    memcpy(f->filename, filename, filename_size);
    memcpy(f->extension, extension, extension_size);
    memcpy(f->data, data, size);
    f->size = size;
}
//Returning file's descriptor if file made without errors and returning error's code
int CreateFile(file* f)
{
    return __CreateFile((f->filename)+'.'+(f->extension));
}
int CloseFile(int descriptor)
{
    int code = __CloseFile(descriptor);
    if (code == descriptor)
    {
        return 0;
    }
    else
    {
        return code;
    }
}
int CreateFile1(file* f)
{
    return __CreateFileWithoutDelete((f->filename)+'.'+(f->extension));
}
int mkdir(char* folder)
{
    return __mkdir(folder);
}
int rmdir(char* folder)
{
    return __rmdir(folder);
}
int SetCurFolder(char* folder)
{
    return __setcurrentfolder(folder);
}
char* GetCurFolder(char* folder)
{
    char* currentFolder = __getcurrentfolder();
    memcpy(folder, currentFolder, strlen(currentFolder));
    return currentFolder;
}
int OpenFile(char* filename)
{
    return __openfile(filename);
}
int WriteFile(int descriptor, char* data, size_t size)
{
    return __writefile(descriptor, data, size);
}
char* ReadFile(int descriptor, char* buffer, size_t size)
{
    read = __readfile(descriptor, size);
    buffer = read;
    return read;
}