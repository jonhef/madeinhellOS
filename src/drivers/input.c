#include "input.h"
#include "lowlevel_io.h"
#include "keyboard.h"

struct string input()
{
    u16 key = get_key();
    struct string res;
    string_init(&res);
    bool is_shift = false;
    bool is_caps_lock = false;
    bool num_lock = false;
    for (int i = 0; i < 4096 && key != KP_ENTER; ++i)
    {
        switch (key)
        {
        case KP_CAPS_LOCK:
            is_caps_lock = !is_caps_lock;
            break;
        case KP_LEFT_SHIFT:
            is_shift = true;
            break;
        case KP_RIGHT_SHIFT:
            is_shift = true;
            break;
        case KR_LEFT_SHIFT:
            is_shift = false;
            break;
        case KR_RIGHT_SHIFT:
            is_shift = false;
            break;
        case KP_1:
            if (is_shift)
            {
                string_append_char(&res, '!');
            }
            else
            {
                string_append_char(&res, '1');
            }
            break;  
        case KP_2:
            if (is_shift)
            {
                string_append_char(&res, '@');
            }
            else
            {
                string_append_char(&res, '2');
            }
            break;
        case KP_3:
            if (is_shift)
            {
                string_append_char(&res, '#');
            }
            else
            {
                string_append_char(&res, '3');
            }
            break;
        case KP_4:
            if (is_shift)
            {
                string_append_char(&res, '$');
            }
            else
            {
                string_append_char(&res, '4');
            }
            break;
        case KP_5:
            if (is_shift)
            {
                string_append_char(&res, '%');
            }
            else
            {
                string_append_char(&res, '5');
            }
            break;
        case KP_6:
            if (is_shift)
            {
                string_append_char(&res, '^');
            }
            else
            {
                string_append_char(&res, '6');
            }
            break;
        case KP_7:
            if (is_shift)
            {
                string_append_char(&res, '&');
            }
            else
            {
                string_append_char(&res, '7');
            }
            break;
        case KP_8:
            if (is_shift)
            {
                string_append_char(&res, '*');
            }
            else
            {
                string_append_char(&res, '8');
            }
            break;
        case KP_9:
            if (is_shift)
            {
                string_append_char(&res, '(');
            }
            else
            {
                string_append_char(&res, '9');
            }
            break;
        case KP_0:
            if (is_shift)
            {
                string_append_char(&res, ')');
            }
            else
            {
                string_append_char(&res, '0');
            }
            break;
        case KP_MINUS:
            if (is_shift)
            {
                string_append_char(&res, '_');
                break;
            }
            string_append_char(&res, '-');
            break;
        case KP_EQUALS:
            if (is_shift)
            {
                string_append_char(&res, '+');
                break;
            }
            string_append_char(&res, '=');
            break;
        case KP_BACKSPACE:
            --res.size;
            res.data[res.size] = '\0';
            break;
        case KP_TAB:
            string_append_char(&res, '\t');
            break;
        case KP_Q:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'Q');
            else
                string_append_char(&res, 'q');
            break;
        case KP_W:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'W');
            else
                string_append_char(&res, 'w');
            break;
        case KP_E:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'E');
            else
                string_append_char(&res, 'e');
            break;
        case KP_R:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'R');
            else
                string_append_char(&res, 'r');
            break;
        case KP_T:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'T');
            else
                string_append_char(&res, 't');
            break;
        case KP_Y:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'Y');
            else
                string_append_char(&res, 'y');
            break;
        case KP_U:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'U');
            else
                string_append_char(&res, 'u');
            break;
        case KP_I:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'I');
            else
                string_append_char(&res, 'i');
            break;
        case KP_O:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'O');
            else
                string_append_char(&res, 'o');
            break;
        case KP_P:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'P');
            else
                string_append_char(&res, 'p');
            break;
        case KP_LEFT_BRACKET:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '{');
            else
                string_append_char(&res, '[');
            break;
        case KP_RIGHT_BRACKET:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '}');
            else
                string_append_char(&res, ']');
            break;
        case KP_ENTER:
            string_append_char(&res, '\n');
            return res;
        case KP_A:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'A');
            else
                string_append_char(&res, 'a');
            break;
        case KP_S:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'S');
            else
                string_append_char(&res, 's');
            break;
        case KP_D:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'D');
            else
                string_append_char(&res, 'd');
            break;
        case KP_F:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'F');
            else
                string_append_char(&res, 'f');
            break;
        case KP_G:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'G');
            else
                string_append_char(&res, 'g');
            break;
        case KP_H:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'H');
            else
                string_append_char(&res, 'h');
            break;
        case KP_J:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'J');
            else
                string_append_char(&res, 'j');
            break;
        case KP_K:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'K');
            else
                string_append_char(&res, 'k');
            break;
        case KP_L:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'L');
            else
                string_append_char(&res, 'l');
            break;
        case KP_SEMICOLON:
            if (is_shift != is_caps_lock)
                string_append_char(&res, ':');
            else
                string_append_char(&res, ';');
            break;
        case KP_APOSTROPHE:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '"');
            else
                string_append_char(&res, '\'');
            break;
        case KP_GRAVE:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '~');
            else
                string_append_char(&res, '`');
            break;
        case KP_BACKSLASH:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '|');
            else
                string_append_char(&res, '\\');
            break;
        case KP_Z:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'Z');
            else
                string_append_char(&res, 'z');
            break;
        case KP_X:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'X');
            else
                string_append_char(&res, 'x');
            break;
        case KP_C:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'C');
            else
                string_append_char(&res, 'c');
            break;
        case KP_V:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'V');
            else
                string_append_char(&res, 'v');
            break;
        case KP_B:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'B');
            else
                string_append_char(&res, 'b');
            break;
        case KP_N:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'N');
            else
                string_append_char(&res, 'n');
            break;
        case KP_M:
            if (is_shift != is_caps_lock)
                string_append_char(&res, 'M');
            else
                string_append_char(&res, 'm');
            break;
        case KP_COMMA:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '<');
            else
                string_append_char(&res, ',');
            break;
        case KP_PERIOD:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '>');
            else
                string_append_char(&res, '.');
            break;
        case KP_SLASH:
            if (is_shift != is_caps_lock)
                string_append_char(&res, '?');
            else
                string_append_char(&res, '/');
            break;
        case KP_SPACE:
            string_append_char(&res, ' ');
            break;
        case KP_NUM_LOCK:
            num_lock = !num_lock;
            break;
        case KP_NUMPAD_7:
            if (!num_lock)
                string_append_char(&res, '7');
            break;
        case KP_NUMPAD_8:
            if (!num_lock)
                string_append_char(&res, '8');
            break;
        case KP_NUMPAD_9:
            if (!num_lock)
                string_append_char(&res, '9');
            break;
        case KP_NUMPAD_MINUS:
            string_append_char(&res, '-');
            break;
        case KP_NUMPAD_4:
            if (!num_lock)
                string_append_char(&res, '4');
            break;
        case KP_NUMPAD_5:
            if (!num_lock)
                string_append_char(&res, '5');
            break;
        case KP_NUMPAD_6:
            if (!num_lock)
                string_append_char(&res, '6');
            break;
        case KP_NUMPAD_PLUS:
            string_append_char(&res, '+');
            break;
        case KP_NUMPAD_1:
            if (!num_lock)
                string_append_char(&res, '1');
            break;
        case KP_NUMPAD_2:
            if (!num_lock)
                string_append_char(&res, '2');
            break;
        case KP_NUMPAD_3:
            if (!num_lock)
                string_append_char(&res, '3');
            break;
        case KP_NUMPAD_0:
            if (!num_lock)
                string_append_char(&res, '0');
            break;
        case KP_NUMPAD_PERIOD:
            string_append_char(&res, '.');
            break;
        }
        key = get_key();
    }
    return res;
}