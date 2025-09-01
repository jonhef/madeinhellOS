#include "../common.h"
#include "lowlevel_io.h"

// Макросы для отпусканий клавиш (KR)
#define KR_ESC             0x81
#define KR_1               0x82
#define KR_2               0x83
#define KR_3               0x84
#define KR_4               0x85
#define KR_5               0x86
#define KR_6               0x87
#define KR_7               0x88
#define KR_8               0x89
#define KR_9               0x8A
#define KR_0               0x8B
#define KR_MINUS           0x8C  // '-'
#define KR_EQUALS          0x8D  // '='
#define KR_BACKSPACE       0x8E
#define KR_TAB             0x8F
#define KR_Q               0x90
#define KR_W               0x91
#define KR_E               0x92
#define KR_R               0x93
#define KR_T               0x94
#define KR_Y               0x95
#define KR_U               0x96
#define KR_I               0x97
#define KR_O               0x98
#define KR_P               0x99
#define KR_LEFT_BRACKET    0x9A  // '['
#define KR_RIGHT_BRACKET   0x9B  // ']'
#define KR_ENTER           0x9C
#define KR_LEFT_CTRL       0x9D
#define KR_A               0x9E
#define KR_S               0x9F
#define KR_D               0xA0
#define KR_F               0xA1
#define KR_G               0xA2
#define KR_H               0xA3
#define KR_J               0xA4
#define KR_K               0xA5
#define KR_L               0xA6
#define KR_SEMICOLON       0xA7  // ';'
#define KR_APOSTROPHE      0xA8  // '''
#define KR_GRAVE           0xA9  // '`'
#define KR_LEFT_SHIFT      0xAA
#define KR_BACKSLASH       0xAB  // '\'
#define KR_Z               0xAC
#define KR_X               0xAD
#define KR_C               0xAE
#define KR_V               0xAF
#define KR_B               0xB0
#define KR_N               0xB1
#define KR_M               0xB2
#define KR_COMMA           0xB3  // ','
#define KR_PERIOD          0xB4  // '.'
#define KR_SLASH           0xB5  // '/'
#define KR_RIGHT_SHIFT     0xB6
#define KR_ASTERISK        0xB7  // '*' на Numpad
#define KR_LEFT_ALT        0xB8
#define KR_SPACE           0xB9
#define KR_CAPS_LOCK       0xBA
#define KR_F1              0xBB
#define KR_F2              0xBC
#define KR_F3              0xBD
#define KR_F4              0xBE
#define KR_F5              0xBF
#define KR_F6              0xC0
#define KR_F7              0xC1
#define KR_F8              0xC2
#define KR_F9              0xC3
#define KR_F10             0xC4
#define KR_NUM_LOCK        0xC5
#define KR_SCROLL_LOCK     0xC6
#define KR_NUMPAD_7        0xC7
#define KR_NUMPAD_8        0xC8
#define KR_NUMPAD_9        0xC9
#define KR_NUMPAD_MINUS    0xCA
#define KR_NUMPAD_4        0xCB
#define KR_NUMPAD_5        0xCC
#define KR_NUMPAD_6        0xCD
#define KR_NUMPAD_PLUS     0xCE
#define KR_NUMPAD_1        0xCF
#define KR_NUMPAD_2        0xD0
#define KR_NUMPAD_3        0xD1
#define KR_NUMPAD_0        0xD2
#define KR_NUMPAD_PERIOD   0xD3  // '.'
#define KR_F11             0xD7
#define KR_F12             0xD8

// Двубайтовые сканкоды
#define KR_RIGHT_CTRL      0xE09D
#define KR_RIGHT_ALT       0xE0B8
#define KR_INSERT          0xE0D2
#define KR_DELETE          0xE0D3
#define KR_HOME            0xE0C7
#define KR_END             0xE0CF
#define KR_PAGE_UP         0xE0C9
#define KR_PAGE_DOWN       0xE0D1
#define KR_ARROW_UP        0xE0C8
#define KR_ARROW_DOWN      0xE0D0
#define KR_ARROW_LEFT      0xE0CB
#define KR_ARROW_RIGHT     0xE0CD
#define KR_LEFT_WINDOWS    0xE0DB
#define KR_RIGHT_WINDOWS   0xE0DC
#define KR_APPLICATION     0xE0DD

#define get_key() inw(0x60)