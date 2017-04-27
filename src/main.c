#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <allegro5/allegro.h>
#include <locale.h>
#include <allegro5/allegro_native_dialog.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro_font.h>

FILE *C, *X;
double *A = NULL, s, m = 0.0;
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

	
	char KEY_CODES[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0' };
	int  m = 0, h = 0, c = 0;
	char a, k;
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
	ALLEGRO_USTR* str = al_ustr_new("Pack my box with five dozen liquor jugs.");
	ALLEGRO_USTR* tab = al_ustr_new("");
	int pos = (int)al_ustr_size(str);
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
		al_draw_multiline_ustr(font, al_map_rgb_f(1, 1, 1), 0, 20, 100, 20, 0, tab);
		//al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 0, 20, 0, tab);
		al_flip_display();

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		C = fopen("input.txt", "r");
		X = fopen("input1.txt", "w");

		m = h = ev.keyboard.keycode-1;
		while (h != -1 && (fscanf(C, "%f", &N)) >= 0)
		{
			if (h == 0)
			{
				A = (double*)realloc(A, (i + 1) * sizeof(double));
				A[i] = N;
				s = s + A[i];
				i++;
			}
			else
			{
				fprintf(X, " %f", N);
			}
			if (fgetc(C) == '\n')
			{
				h--;
				if (h != 0 && m != 0)
					fprintf(X, "\n");
			}
		}
		if (m == 6)
			fprintf(X, "\n");

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			quit = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				al_ustr_append_cstr(tab, "\n");
				//quit = true;
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
		for (j = 0; j<i; j++)
			fprintf(X, " %f", A[j]);
		fprintf(X, "\n");

		while (fscanf(C, "%f", &N) >= 0)
		{
			fprintf(X, " %f", N);
			if (fgetc(C) == '\n')
			{
				fprintf(X, "\n");
			}

		}
		fclose(C);
		fclose(X);
		//fclose(X);
		C = fopen("input.txt", "w");
		X = fopen("input1.txt", "r");
		// fseek(X,0,SEEK_SET);
		while (!feof(X))
		{
			fscanf(X, "%f", &N);
			fprintf(C, " %f", N);
			if (fgetc(X) == '\n')
			{
				fprintf(C, "\n");
			}
		}
		//fclose(X);
		//remove("input1.txt");
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
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}

double Stewdent(int i)//Выводит коэфициент Стьюдента
{
	if (i == 2)
		return 12.71;
	if (i == 3)
		return 4.30;
	if (i == 4)
		return 3.188;
	if (i == 5)
		return 2.77;
	if (i == 6)
		return 2.57;
	if (i == 7)
		return 2.45;
	if (i == 8)
		return 2.36;
	if (i == 9)
		return 2.31;
	if (i == 10)
		return 2.26;
	if (i <= 12 && i>10)
		return 2.20;
	if (i <= 14 && i>12)
		return 2.16;
	if (i <= 16 && i>14)
		return 2.13;
	if (i <= 18 && i>16)
		return 2.11;
	if (i <= 20 && i>18)
		return 2.09;
	if (i <= 30 && i>20)
		return 2.04;
	if (i <= 40 && i>30)
		return 2.02;
	if (i <= 50 && i>40)
		return 2.01;
	if (i <= 60 && i>50)
		return 2.00;
	if (i > 60)
		return 1.96;

}

int main(void) { //Считает погрешности с динамическим выделением памяти
	double sr_zn = 0.0, disp = 0.0, t = 0.0, k = 0.0;
	int j;
	setlocale(LC_ALL, "Rus");
	int a;
	input();
	sr_zn = s / i;
	if (i != 1)
	{
		for (j = 0; j<i; j++)
		{
			k = k + (A[j] - sr_zn)*(A[j] - sr_zn);
		}
		disp = sqrt(k / (i*(i - 1)));
		t = disp*Stewdent(i);
		k = 0;
	}
	printf("Сумма=%lf\n", s);
	printf("Cреднее значение=%lf\n", sr_zn);
	printf("Дисперсия=%lf\n", disp);
	printf("Погрешность:%lf\n", t);
	getchar();
	return 0;

}