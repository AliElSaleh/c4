#pragma once

#include <X11/X.h>

typedef enum
{
    C4_KEY_UNKNOWN,

	C4_KEY_1,
	C4_KEY_2,
	C4_KEY_3,
	C4_KEY_4,
	C4_KEY_5,
	C4_KEY_6,
	C4_KEY_7,
	C4_KEY_8,
	C4_KEY_9,
	C4_KEY_0,

	C4_KEY_TILDE,
	C4_KEY_BACKTICK,
	C4_KEY_EXCLAMATION_MARK,
	C4_KEY_AT,
	C4_KEY_HASHTAG,
	C4_KEY_DOLLAR,
	C4_KEY_PERCENT,
	C4_KEY_CARET,
	C4_KEY_AMPERSAND,
	C4_KEY_ASTERISK,
	C4_KEY_L_PARENS,
	C4_KEY_R_PARENS,
	C4_KEY_UNDERSCORE,
	C4_KEY_MINUS,
	C4_KEY_PLUS,
	C4_KEY_EQUALS,
	C4_KEY_BACKSPACE,

	C4_KEY_A,
	C4_KEY_B,
	C4_KEY_C,
	C4_KEY_D,
	C4_KEY_E,
	C4_KEY_F,
	C4_KEY_G,
	C4_KEY_H,
	C4_KEY_I,
	C4_KEY_J,
	C4_KEY_K,
	C4_KEY_L,
	C4_KEY_M,
	C4_KEY_N,
	C4_KEY_O,
	C4_KEY_P,
	C4_KEY_Q,
	C4_KEY_R,
	C4_KEY_S,
	C4_KEY_T,
	C4_KEY_U,
	C4_KEY_V,
	C4_KEY_W,
	C4_KEY_X,
	C4_KEY_Y,
	C4_KEY_Z,

	C4_KEY_SPACE,

	C4_KEY_L_BRACKET,
	C4_KEY_R_BRACKET,
	C4_KEY_L_BRACE,
	C4_KEY_R_BRACE,
	C4_KEY_PIPE,
	C4_KEY_BACKSLASH,
	C4_KEY_COLON,
	C4_KEY_SEMICOLON,
	C4_KEY_DOUBLE_QUOTE,
	C4_KEY_SINGLE_QUOTE,
	C4_KEY_L_ANGLE_BRACKET,
	C4_KEY_R_ANGLE_BRACKET,
	C4_KEY_QUESTION_MARK,
	C4_KEY_COMMA,
	C4_KEY_POINT,
	C4_KEY_SLASH,

	C4_KEY_TAB,
	C4_KEY_CAPS_LOCK,
	C4_KEY_ENTER,

	C4_KEY_L_SHIFT,
	C4_KEY_R_SHIFT,
	C4_KEY_L_CTRL,
	C4_KEY_R_CTRL,
	C4_KEY_L_ALT,
	C4_KEY_R_ALT,

	C4_KEY_L_SUPER,
	C4_KEY_R_SUPER,

	C4_KEY_ARROW_LEFT,
	C4_KEY_ARROW_UP,
	C4_KEY_ARROW_RIGHT,
	C4_KEY_ARROW_DOWN,

	C4_KEY_HOME,
	C4_KEY_PAGE_UP,
	C4_KEY_END,
	C4_KEY_PAGE_DOWN,

	/// THE ESCAPE KEY, NEXT TO F1.
	C4_KEY_ESCAPE,

	C4_KEY_F1,
	C4_KEY_F2,
	C4_KEY_F3,
	C4_KEY_F4,
	C4_KEY_F5,
	C4_KEY_F6,
	C4_KEY_F7,
	C4_KEY_F8,
	C4_KEY_F9,
	C4_KEY_F10,
	C4_KEY_F11,
	C4_KEY_F12,

	C4_KEY_DELETE,
	C4_KEY_PLAY,
	C4_KEY_STOP,
	C4_KEY_PREV_TRACK,
	C4_KEY_NEXT_TRACK,
	C4_KEY_PRINT_SCREEN,

	C4_KEY_NUM_LOCK,
	C4_KEY_NUMPAD_0,
	C4_KEY_NUMPAD_1,
	C4_KEY_NUMPAD_2,
	C4_KEY_NUMPAD_3,
	C4_KEY_NUMPAD_4,
	C4_KEY_NUMPAD_5,
	C4_KEY_NUMPAD_6,
	C4_KEY_NUMPAD_7,
	C4_KEY_NUMPAD_8,
	C4_KEY_NUMPAD_9,
	C4_KEY_NUMPAD_ADD,
	C4_KEY_NUMPAD_DIVIDE,
	C4_KEY_NUMPAD_DECIMAL,
	C4_KEY_NUMPAD_COMMA,
	C4_KEY_NUMPAD_ENTER,
	C4_KEY_NUMPAD_EQUALS,
	C4_KEY_NUMPAD_MULTIPLY,
	C4_KEY_NUMPAD_SUBTRACT,
} C4_KeyCode;

C4_KeyCode keysym_to_keycode(XID keysym);
char* keycode_display(C4_KeyCode keycode);
