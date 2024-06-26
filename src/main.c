#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "app/app.h"
#include "audio/audio.h"
#include "core/alloc/core_arena.h"
#include "core/os/core_os.h"
#include "types.h"

int main(void)
{
	Arena arena = arena_init(os_total_ram());

	srand(time(NULL));

	AudioContext* audio_ctx = arena_alloc(&arena, AudioContext);
	if (audio_open(audio_ctx) == false)
	{
		fprintf(stderr, "could not open audio :(\n");
		return 1;
	}

	AudioBuffer audio_buffer;
	audio_buffer.len = 256;
	audio_buffer.ptr = arena_alloc_region(&arena, audio_buffer.len, 16);

	printf("sending audio frames\n");
	for (u32 j = 0; j < 64; j++)
	{
		printf("  frame #%d\n", j);

		for (usize i = 0; i < audio_buffer.len; i++)
			audio_buffer.ptr[i] = rand() & 0x7f;

		audio_write(audio_ctx, audio_buffer);
	}

	printf("sent audio frames\n");
	audio_close(audio_ctx);

	arena_free_all(&arena);
	arena_destroy(&arena);

	///////////////////////////////////

	printf("initializing windowing\n");
	app_init();
	printf("windowing initialized\n");

	u32 const WIDTH  = 1280;
	u32 const HEIGHT = 720;

	printf("options\n");
	char*            title   = "C4 Window";
	C4_WindowOptions options = {
	    .title       = title,
	    .position    = {.x = 0, .y = 0},
	    .size        = {.width = WIDTH, .height = HEIGHT},
	    .monitor     = {0},
	    .screen_mode = WINDOWED,
	    .flags       = WINDOW_FLAG_RESIZABLE | WINDOW_FLAG_CENTERED | WINDOW_FLAG_TRANSPARENT | WINDOW_FLAG_HIGH_DPI,
	};

	printf("opening window\n");
	C4_Window* window = NULL;
	if (app_open_window(options, &window) == false)
	{
		fprintf(stderr, "Nope, no window\n");
		return 1;
	}

	u32 event_count = 0;

	C4_Event event = {0};
	while (app_poll_event(&event))
	{
		bool quit = false;

		switch (event.tag)
		{
			case C4_EVENT_KEYBOARD:
			{
				C4_KeyboardEvent kev = event.kind.keyboard;

				char* key_event_str;
				switch (kev.tag)
				{
					case C4_KEYBOARD_EVENT_KEY_PRESS:
						key_event_str = "KeyPress  ";
						break;
					case C4_KEYBOARD_EVENT_KEY_RELEASE:
						key_event_str = "KeyRelease";
						break;
					case C4_KEYBOARD_EVENT_KEY_REPEAT:
						key_event_str = "KeyRepeat ";
						break;
					case C4_KEYBOARD_EVENT_IME_COMMIT:
						key_event_str = "ImeCommit ";
						break;
				}

				bool  is_ime_commit = kev.tag == C4_KEYBOARD_EVENT_IME_COMMIT;
				char* key_data      = is_ime_commit ? kev.kind.ime_commit.ptr : keycode_display(kev.kind.key_press);

				printf("Received event %s |「%s」\n", key_event_str, key_data);

				if (kev.kind.key_press == C4_KEY_Q)
					quit = true;

				break;
			}

			case C4_EVENT_MOVED:
			{
				C4_EventKindMoved mev = event.kind.moved;
				printf("Window moved to (%d, %d)\n", mev.pos.x, mev.pos.y);
				break;
			}

			case C4_EVENT_RESIZED:
			{
				C4_EventKindResized rev = event.kind.resized;
				printf("Window resized to (%d, %d)\n", rev.size.width, rev.size.height);
				break;
			}

			default:
				printf("Received event (?)        | %d\n", event_count++);
				break;
		}

		if (event.window != NULL)
		{
			printf("committing framebuffer\n");
			app_commit_framebuffer(event.window);
		}

		if (quit)
			break;
	}

	printf("closing window\n");
	app_close_window(window);

	printf("quitting\n");
	return 0;
}
