; ------------------------------------------------------------------------------
; Guide:	00-BOOT-SECTOR
; File:		ex02 / main.asm
; Title:	Простая программа загрузочного сектора (boot sector), которая 
;			демонстрирует работу адресов
; ------------------------------------------------------------------------------
; Description: 
;	Наша цель - разобраться как работать с памятью на языке Ассемблер и узнать,
;	по какому адресу хранится загрузочный сектор (спойлер: по адресу 0x7c00).
;	Для этого мы попробуем вывести символ 'Х' на экран 4-мя разными способами.
;	Подготовка: если addr - адрес, то [addr] - значение на которое указывает 
;	адрес
; ------------------------------------------------------------------------------


mov ah, 0x0e			; Перемещаем число 0x0e в регистр ah, указывая BIOS'у
						; что нам нужна рутина tele-type, то есть режим вывода 
						; информации на экран

mov al, '1'				; Выводим номер способа (нужно лишь нам для понятности)
int 0x10
mov al, the_secret		; #1: перемещаем адрес the_secret.
int 0x10				; На экран выведется мусор, т.к. мы переместили в al 
						; сам адрес, а не хранящееся в нем значение.

mov al, '2'				; Выводим номер способа
int 0x10
mov al, [the_secret]	; #2: перемещаем значение по адресу the_secret.
int 0x10				; Может показаться вполне корректным, но на экран снова
						; выведется мусор, т.к the_secret объявлен не в том же
						; месте, что и наш загрузочный сектор, и поэтому мы не
						; сможем таким образом забрать из него 'X'.

mov al, '3'				; Выводим номер способа
int 0x10
mov bx, the_secret		; #3: перемещаем адрес the_secret в регистр bx,
add bx, 0x7c00			; добавляем к этому адресу адрес загрузочного сектора,
mov al, [bx]			; выводим значение по адресу bx.
int 0x10				; Вот теперь то мы и сможем вывести 'X'. Суть в том, что
						; чтобы мы смогли добраться до корректного значения
						; которое мы объявили, адрес этого значения должен быть
						; в пределах адресного пространства загрузочного 
						; сектора. Т.е. мы должны прибавить к адресу the_secret
						; адрес, с которого начинается загрузочный сектор.
						; то есть если the_secret = 0x2d, то прибавляя к нему
						; адрес загрузочного сектора 0x7c00 мы получим 0x7c2d.
						; Такая техника называется смещением (англ. offset)
						; Именно по этому адресу мы сможем достать 'X'.

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