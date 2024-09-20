; Compile with FASM
section .text

global __CreateFileWithoutDelete

__CreateFileWithoutDelete:
    ; rcx - file's name
    mov ah,5Bh
    mov dx,[rcx]
    xor cx,cx
    int 21h
    jnc close_file
    call error_msg
    jmp exit

close_file:
    mov rax, ax
    mov ah,3Eh
    mov bx,rax
    int 21h
    jnc exit
    jc error_msg

exit:
    ret

;-------------------------------------------------------------------------------
; Returning error
error_msg:
    mov rax, s_error        ;Return error
    ret