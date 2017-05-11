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
#define MAX_SIZE 50
#define MAX_LATTER 26

FILE *C,*NAME,*X;
double A[MAX_LATTER][MAX_SIZE], B[MAX_LATTER], D[MAX_LATTER][2];

int output()
{
	//Переменные
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	int j, count = 0, k = 0 , count_1 = 0;
	double time_A = 0.0, sr_zn = 0.0, sum = 0;
	double time_B = 0.0;
	char name[20];
	bool quit = false;
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
	ALLEGRO_USTR* str = al_ustr_new("Please enter this sentence: pack my box with five dozen liquor jugs.");
	ALLEGRO_USTR* tab = al_ustr_new("");
	int pos1 = (int)al_ustr_size(tab);
	//Инициализация

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//
	while (!quit)
	{
		al_clear_to_color(al_map_rgb_f(0, 0, 0));
		al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 0, 0, 0, str);
		al_draw_multiline_ustr(font, al_map_rgb_f(1, 1, 1), 0, 20, 400, 20, 0, tab);
		al_flip_display();

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			quit = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				quit = true;
			}
			time_A = al_get_time();
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		 {
				time_B = al_get_time();
				while (A[ev.keyboard.keycode - 1][k] != 0)
				{
					k++;
				}
				A[ev.keyboard.keycode - 1][k] = time_B - time_A;
				sr_zn = time_B - time_A;
				if(k!=0)
				{
				for (count = 0; count < k; count++)
				{
					sum = sum + A[ev.keyboard.keycode - 1][count];
				}
					sr_zn = sum / k;
				}
				k = 0;
				sum = 0;
				B[ev.keyboard.keycode - 1] = sr_zn;

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
	NAME = fopen("NAME", "r");
		fscanf(NAME, "%s", &name);
		strncat1(name);
		C = fopen(name, "r");
		for (count = 0; count < MAX_LATTER; ++count)
		{
			for (j = 0; j < 2; ++j)
			{
				fscanf(C, "%lf", &D[count][j]);
			}
			if (B[count] < (D[count][0] + D[count][1]) && B[count] > (D[count][0] - D[count][1]))
			{
				 ++count_1;
			}
		}
		fclose(C);
	X = fopen("toto.txt", "w");
	for (j = 0; j<MAX_LATTER; j++)
		{
			fprintf(X, "%.8lf ", B[j]);
			fprintf(X, "\n");
		}
	fclose(X);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	printf("%i ", count_1);
	if (count_1 > 21)
		return 1;
	else
		return 0;
}
