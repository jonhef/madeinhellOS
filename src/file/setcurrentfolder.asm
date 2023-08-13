; Compile with FASM
section .text

global __setcurrentfolder

__setcurrentfolder:
    mov ah, 3Bh
    mov dx, [rcx]
    int 21h
    mov rax, cf
    ret