#pragma once

#include "../types.h"

typedef enum
{
	KEY1,
	KEY2,
	KEY3,
	KEY4,
	KEY5,
	KEY6,
	KEY7,
	KEY8,
	KEY9,
	KEY0,

	TILDE,
	BACKTICK,
	EXCLAMATION_MARK,
	AT,
	HASHTAG,
	DOLLAR,
	PERCENT,
	CARET,
	AMPERSAND,
	ASTERISK,
	L_PARENS,
	R_PARENS,
	UNDERSCORE,
	MINUS,
	PLUS,
	EQUALS,
	BACKSPACE,

	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,

	SPACE,

	L_BRACKET,
	R_BRACKET,
	L_BRACE,
	R_BRACE,
	PIPE,
	BACKSLASH,
	COLON,
	SEMICOLON,
	DOUBLE_QUOTE,
	SINGLE_QUOTE,
	L_ANGLE_BRACKET,
	R_ANGLE_BRACKET,
	QUESTION_MARK,
	COMMA,
	POINT,
	SLASH,

	TAB,
	CAPS_LOCK,
	ENTER,

	L_SHIFT,
	R_SHIFT,
	L_CTRL,
	R_CTRL,
	L_ALT,
	R_ALT,

	L_WIN,
	R_WIN,
	L_SUPER,
	R_SUPER,
	L_COMMAND,
	R_COMMAND,

	ARROW_LEFT,
	ARROW_UP,
	ARROW_RIGHT,
	ARROW_DOWN,

	HOME,
	PAGE_UP,
	END,
	PAGE_DOWN,

	/// THE ESCAPE KEY, NEXT TO F1.
	ESCAPE,

	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,

	DELETE,
	PLAY,
	STOP,
	PREV_TRACK,
	NEXT_TRACK,
	PRINT_SCREEN,

	NUM_LOCK,
	NUMPAD0,
	NUMPAD1,
	NUMPAD2,
	NUMPAD3,
	NUMPAD4,
	NUMPAD5,
	NUMPAD6,
	NUMPAD7,
	NUMPAD8,
	NUMPAD9,
	NUMPAD_ADD,
	NUMPAD_DIVIDE,
	NUMPAD_DECIMAL,
	NUMPAD_COMMA,
	NUMPAD_ENTER,
	NUMPAD_EQUALS,
	NUMPAD_MULTIPLY,
	NUMPAD_SUBTRACT,
} C4_KeyCode;

typedef enum
{
	KEYBOARD_EVENT_KEY_PRESS,
	KEYBOARD_EVENT_KEY_RELEASE,
	KEYBOARD_EVENT_KEY_REPEAT,
	KEYBOARD_EVENT_IME_COMMIT,
} C4_KeyboardEventTag;

typedef struct
{
	C4_KeyCode key_code;
} C4_KeyboardEventKeyPress;

typedef struct
{
	C4_KeyCode key_code;
} C4_KeyboardEventKeyRelease;

typedef struct
{
	C4_KeyCode key_code;
} C4_KeyboardEventKeyRepeat;

typedef struct
{
	String8 content;
} C4_KeyboardEventImeCommit;

typedef union
{
	C4_KeyboardEventKeyPress   key_press;
	C4_KeyboardEventKeyRelease key_release;
	C4_KeyboardEventKeyRepeat  key_repeat;
	C4_KeyboardEventImeCommit  ime_commit;
} C4_KeyboardEventKind;

typedef struct
{
	C4_KeyboardEventTag  tag;
	C4_KeyboardEventKind kind;
} C4_KeyboardEvent;
