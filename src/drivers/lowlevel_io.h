/*------------------------------------------------------------------------------
*	Guide:	01-KERNEL
*	File:	ex01 / drivers / lowlevel_io.h
*	Title:	Заголовочный файл для lowlevel_io.c
* ------------------------------------------------------------------------------
*	Description:
* ----------------------------------------------------------------------------*/


unsigned char   port_byte_in(unsigned short port);
void    port_byte_out(unsigned short port, unsigned char data);
unsigned short   port_word_in(unsigned short port);
void port_word_out(unsigned short port, unsigned short data);

#ifndef inb
#define inb port_byte_in
#endif

#ifndef outb
#define outb port_byte_out
#endif

#ifndef inw
#define inw port_word_in
#endif

#ifndef outw
#define outw port_byte_out
#endif