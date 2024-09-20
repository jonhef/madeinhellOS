; compile with FASM
section .text

global __CreateFile

__CreateFile:
    ; rcx - file's name
    mov ah,3Ch
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