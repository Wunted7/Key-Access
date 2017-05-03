#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <allegro5/allegro.h>
#include <locale.h>
#include <allegro5/allegro_native_dialog.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro_font.h>
#include "input.h"

FILE *C;
double *A = NULL , s;
int i;
int input()
{
	//Переменные
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	double N;
	int j;
	double time_A = 0.0;
	double time_B = 0.0;
	double time_C = 0.0;
	bool quit = false;

	//char KEY_CODES[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', };
	//KEY_CODES[74] = ' ';

	//
	if (!al_init()) {
		return -1;
	}

	if (!al_install_keyboard()) {
		return -1;
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	display = al_create_display(800, 600);
	if (!display) {
		return -1;
	}

	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_USTR* str = al_ustr_new("pack my box with five dozen liquor jugs.");
	ALLEGRO_USTR* tab = al_ustr_new("");
	int pos = (int)al_ustr_size(str);
	int pos1 = (int)al_ustr_size(tab);
	//Инициализация

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//

	C = fopen("input.bin", "rb");


	while (fread(&N, sizeof(double), 1, C) > 0)//Берет информацию из файла и записывает в динамический массив
	{
		A = (double*)realloc(A, (i + 1) * sizeof(double));
		A[i] = N;
		s += A[i];
		i++;
	}
	fclose(C);

	C = fopen("input.bin", "wb");

	while (!quit)
	{
		al_clear_to_color(al_map_rgb_f(0, 0, 0));
		al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 0, 0, 0, str);
		al_draw_multiline_ustr(font, al_map_rgb_f(1, 1, 1), 0, 20, 100, 20, 0, tab);
		//al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 0, 20, 0, tab);
		al_flip_display();

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			quit = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				//al_ustr_append_cstr(tab, "\n");
				quit = true;
			}
			time_A = al_get_time();
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			time_B = al_get_time();
			//fprintf(C, "%c ", KEY_CODES[ev.keyboard.keycode - 1]);
			//printf("%f\n", time_B - time_A);
			A = (double*)realloc(A, (i + 1) * sizeof(double));
			A[i] = time_B - time_A;
			s += A[i];
			++i;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
			if (ev.keyboard.unichar >= 32)
			{
				pos1 += al_ustr_append_chr(tab, ev.keyboard.unichar);
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE)
			{
				if (al_ustr_prev(tab, &pos1))
					al_ustr_truncate(tab, pos1);
			}
		}


	}
	for (j = 0; j < i; ++j) {
		fwrite(&A[j], sizeof(double), 1, C);
	}
	fclose(C);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}
