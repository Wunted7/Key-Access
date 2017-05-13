#include "lib.h"
#define MAX_SIZE 50
#define MAX_LETTER 26

FILE *C, *X, *NAME;
double A[MAX_LETTER][MAX_SIZE], B[MAX_LETTER][2];

int input()
{
	setlocale(LC_ALL, "Rus");
	//Переменные
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	int j, i, k = 0;
	double time_A = 0.0, sr_zn = 0.0, t = 0, sum = 0;
	double time_B = 0.0;
	char name[20];
	printf("Введите свое имя и фамилию без пробелов на английском : ");
	scanf("%s", name);
	NAME = fopen("NAME", "a");
	fprintf(NAME, "%s", name);
	fprintf(NAME, "\n");
	fclose(NAME);
	C = fopen(name, "r");
	if (C != NULL)
	{
		for (i = 0; i < MAX_LETTER; i++)
		{
			for (j = 0; j < MAX_SIZE; j++)
			{
				fscanf(C, "%lf", &A[i][j]);
			}
		}
	}
	else
	{
		C = fopen(name, "w");
	}
	fclose(C);
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
	ALLEGRO_USTR* str = al_ustr_new("Please enter this sentence 13 times , than enter Escape: pack my box with five dozen liquor jugs.");
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
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				quit = true;
			}
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				al_ustr_append_cstr(tab, "\n");
			}
			time_A = al_get_time();
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (ev.keyboard.keycode > 27) {
				continue;
			}
			else {
				time_B = al_get_time();
				while (A[ev.keyboard.keycode - 1][k] != 0)
				{
					k++;
				}
				A[ev.keyboard.keycode - 1][k] = time_B - time_A;
				for (i = 0; i < k; i++)
				{
					sum = sum + A[ev.keyboard.keycode - 1][i];
				}
				sr_zn = sum / k;
				if (k != 1)
				{
					t = delta(k, A[ev.keyboard.keycode - 1], sr_zn);
				}
				k = 0;
				sum = 0;
				B[ev.keyboard.keycode - 1][0] = sr_zn;
				B[ev.keyboard.keycode - 1][1] = t;
			}
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
	C = fopen(name, "w");
	for (i = 0; i<MAX_LETTER; i++) {
		for (j = 0; j<MAX_SIZE; j++) {
			fprintf(C, "%.8lf ", A[i][j]);
		}
		fprintf(C, "\n");
	}
	fclose(C);
	strncat1(name);
	X = fopen(name, "w");
	for (i = 0; i<MAX_LETTER; i++) {
		for (j = 0; j<2; j++) {
			fprintf(X, "%.8lf ", B[i][j]);
		}
		fprintf(X, "\n");
	}
	fclose(X);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}
