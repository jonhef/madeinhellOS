//
// Created by d on 12.08.2023.
//
#include "file.c"

#define fopen OpenFile
#define fwrite WriteFile
#define fread ReadFile
#define fclose CloseFile

struct file;
typedef file file;

void FileInit(file* f, char filename[], char extension[], char* data, size_t size);
//Returning file's descriptor if file made without errors and returning error's code
int CreateFile(file* f);
int CloseFile(int descriptor);
int CreateFile1(file* f);
int mkdir(char* folder);
int rmdir(char* folder);
int SetCurFolder(char* folder);
char* GetCurFolder(char* folder);
int OpenFile(char* filename);
int WriteFile(int descriptor, char* data, size_t size);
char* ReadFile(int descriptor, char* buffer, size_t size);