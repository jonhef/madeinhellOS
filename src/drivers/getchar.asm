; as far as i know it is NASM

global __GetChar

__GetChar:
    mov ah, 0x00
    int 0x16    ; read from keyboard
    mov rax, al
    ret