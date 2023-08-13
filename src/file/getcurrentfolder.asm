; Compile with FASM
section .text

global __getcurrentfolder

section '.data' data readable writeable
    currentFolder db 128 dup(0)

__getcurrentfolder:
    mov ah, 47h
    mov dl, 0
    mov si, offset currentFolder
    int 21h

    lea rax, currentFolder
    ret