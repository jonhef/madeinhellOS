; ------------------------------------------------------------------------------
; Guide:	00-BOOT-SECTOR
; File:		ex02 / org_demo.asm
; Title:	Простая программа загрузочного сектора (boot sector), которая 
;			демонстрирует работу адресов, используя директиву [org <адрес>]
; ------------------------------------------------------------------------------
; Description:
;	Мы выяснили в предыдущем упражнении, что чтобы процессор корректно нашел 
;	объявленное нами значение, нужно добавлять 0x7c00 к адресу этого значения 
;	(т.е. "сместить" адрес на 0x7c00, англ. offset - смещение). Это довольно 
;	неудобно, и поэтому ассемблер позволяет нам указать "глобальное смещение" с 
;	помощью директивы [org <адрес>]. Посмотрим как это работает.
; ------------------------------------------------------------------------------


[org 0x7c00]			; Указываем "глобальное смещение"

mov ah, 0x0e			; Перемещаем число 0x0e в регистр ah, указывая BIOS'у
						; что нам нужна рутина tele-type, то есть режим вывода 
						; информации на экран

mov al, '1'				; Выводим номер способа для удобства
int 0x10
mov al, the_secret		; #1: перемещаем адрес the_secret.
int 0x10				; На экран выведется мусор, т.к. мы переместили в al 
						; сам адрес, а не хранящееся в нем значение.

mov al, '2'				; Выводим номер способа
int 0x10
mov al, [the_secret]	; #2: перемещаем значение по адресу the_secret.
int 0x10				; В этот раз мы сможем вывести 'X', т.к. [the_secret]
						; будет разыменован по адресу the_secret + 0x7c00
						; благодаря "глобальному смещению"

mov al, '3'				; Выводим номер способа
int 0x10
mov bx, the_secret		; #3: перемещаем адрес the_secret в регистр bx,
add bx, 0x7c00			; добавляем к этому адресу адрес загрузочного сектора,
mov al, [bx]			; выводим значение по адресу bx.
int 0x10				; Мы не сможем вывести 'X', т.к. лишний раз делаем
						; смещение: 0x7c00 + the_secret + 0x7c00

mov al, '4'				; Выводим номер способа
int 0x10
mov al, [0x7c2d]		; #4: перемещаем значение адреса, который мы
int 0x10				; захардкодили (т.е. специально сами посчитали, заранее, 
						; не программно) Таким способом у нас тоже получится 
						; вывести 'X', но это плохой способ, т.к. адрес может 
						; в итоге отличаться.

						; ------------------------------------------------------

jmp $					; бесконечный цикл

the_secret:				; Объявляем метку the_secret,
	db 'X'				; объявляем байт, и инициализируем его с ASCII кодом,
						; соответствующим символу 'X'


times 510-($-$$) db 0	; Заполняем ненужные байты нулями

dw 0xaa55				; Вставляем в конец "магическое число"