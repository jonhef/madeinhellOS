; ------------------------------------------------------------------------------
; Guide:	00-BOOT-SECTOR
; File:		ex04 / main.asm
; Title:	Простая программа загрузочного сектора, которая выводит на экран 
;			строку с помощью функции
; ------------------------------------------------------------------------------
; Description:
;	Кратко о том, как работают функции:
;	Чтобы вызвать функцию, используется команда call <метка>. Чтобы вернуть
;	(выйти) из функции, используется команда ret.
;	Команды call и ret используются в паре. Команда call помещает значение 
;	регистра EIP (в нем установлен адрес, следующий после call <метка> 
;	инструкции) в стек, а команда ret извлекает его и передаёт управление 
;	инструкции по этому адресу. Вы также можете определить аргументы, для 
;	вызываемой функции. Это можно сделать с помощью стека или регистров, т.е. 
;	перед вызовом функции занести параметры в стек или в определенный регистр, 
;	а в теле функции извлечь их.
; ------------------------------------------------------------------------------


[org 0x7c00]

mov bx, HELLO_MSG				; Перемещаем объявленную нами ниже строку в
								; регистр BX. В ассемблере строки представляют
								; из себя то же, что и строки в Си - идущие друг
								; за другом ячейки памяти, в которых занесено 
								; значение символов этой строки, поэтому в BX
								; в данный момент находится первый символ строки
								; (а точнее его ASCII код).

call print_string				; Вызываем функцию print_string с помощью
								; команды call

mov bx, GOODBYE_MSG
call print_string

								; ------------------------------------------------------

jmp $							; бесконечный цикл

%include "print_string.asm"		; директива %include вставляет весь код из
								; файла print_string.asm в место, откуда она
								; была вызвана.

HELLO_MSG:
	db "Hello, world!", 0		; Объявляем байты, содержащие строку с 
								; приветствием, заканчивающуюся нулем.
								; На самом деле эти байты размещаются прямо в
								; исполняемом файле, откомпилированном с помощью
								; nasm. Вот так вот.

GOODBYE_MSG:					; Объявляем метку GOODBYE_MSG
	db "Goodbye!", 0			; Объявляем массив из символом, заканчивающийся
								; нулем (гугли: нуль терминированная строка)

times 510-($-$$) db 0			; Заполняем оставшиеся байты нулями
dw 0xaa55						; Вставляем в конец "магическое число"