/*------------------------------------------------------------------------------
*	Guide:	01-KERNEL
*	File:	ex00 / kernel / kernel.c
*	Title:	Программа на Си, в которую мы загрузимся после boot'а.
* ------------------------------------------------------------------------------
*	Description:
* ----------------------------------------------------------------------------*/


void 	func() {}		/* Эта функция нужна чтобы показать, что ядро будет
						загружаться не с начала этого файла (0x00), а с
						функции kmain. Если бы это было не так, то вместо kmain
						код бы начал выполняться с этой функции, а т.к. она
						ничего не делает, то мы бы не получили результата */

void	kmain()
{
	char *video_memory = (char *) 0xb8000;	/* Распологаем символ 'x' по */
	*video_memory = 'x';					/* адресу 0xb8000 */
}