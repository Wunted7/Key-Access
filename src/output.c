#include "lib.h"
#define MAX_SIZE 50
#define MAX_LETTER 26
#define COLUMS_IN_FILE1 2
/*!
@file output.c
@{

\brief
Файл отвечает за авторизацию пользователей
*
*
    *@author Батов Юрий email - batov1998@list.ru\n
    @author Ильченко Никита email - wunted7@gmail.com
*/
/** По введенным значениям инициализирует пользователя, сравнивая его значения с значениями в базе данных
*/
/**
    ##Функция определяет время удержания клавиши и определяет , что за буква была нажата пользователем
    ##Происходит обработка полученных значений (подсчет погрешностей) и сравнение с эталонами
		\return 0 Если пользователь не определен
		\return 1 Если пользователь определен, так же выводится имя пользователя
*/
FILE *C, *NAME, *X;
double A[MAX_LETTER][MAX_SIZE], B[MAX_LETTER], D[MAX_LETTER][COLUMS_IN_FILE1];

int output()
{
	//Переменные
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	int j, count = 0, k = 0, count_1 = 0, max = 0;
	double time_of_press = 0.0, sr_zn = 0.0, sum = 0, time_of_release = 0.0;
	char name[20], name_1[20];
	bool quit = false;
	if (!al_init())
    {
		return -1;
	}
	if (!al_install_keyboard())
    {
		return -1;
	}
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	display = al_create_display(800, 600);
	if (!display)
    {
		return -1;
	}
	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_USTR* str = al_ustr_new("Please enter this sentence: pack my box with five dozen liquor jugs.");
	ALLEGRO_USTR* tab = al_ustr_new("");
	int pos1 = (int)al_ustr_size(tab);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	while (!quit)
	{
		al_clear_to_color(al_map_rgb_f(0, 0, 0));
		al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 0, 0, 0, str);
		al_draw_multiline_ustr(font, al_map_rgb_f(1, 1, 1), 0, 20, 400, 20, 0, tab);
		al_flip_display();

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
			quit = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
			{
				quit = true;
			}
			time_of_press = al_get_time();
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (ev.keyboard.keycode > 27)
			{
				continue;
			}
			else
			{
				time_of_release = al_get_time();
				while (A[ev.keyboard.keycode - 1][k] != 0)
				{
					k++;
				}
				if(k <= MAX_SIZE)
                {
                    A[ev.keyboard.keycode - 1][k] = time_of_release - time_of_press;
				}
				sr_zn = time_of_release - time_of_press;
				if (k != 0)
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
		}
		if (ev.type == ALLEGRO_EVENT_KEY_CHAR)
            {
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
	if (NAME == NULL)
	{
		puts("Problems");
		al_destroy_event_queue(event_queue);
	        al_destroy_display(display);
	}
	while (fscanf(NAME, "%s", name) != EOF)
	{
		strncat1(name);
		C = fopen(name, "r");
		if (C == NULL)
        {
            puts("Problems");
	    al_destroy_event_queue(event_queue);
	    al_destroy_display(display);
        }
		for (count = 0; count < MAX_LETTER; ++count)
		{
			for (j = 0; j < 2; ++j)
			{
				fscanf(C, "%lf", &D[count][j]);
			}
			if (B[count] < (D[count][0] + D[count][1]) && B[count] > (D[count][0] - D[count][1]))
			{
				count_1++;
			}
		}
		fclose(C);
		if (count_1 > max && count_1 > 20)
		{
			max = count_1;
			strcpy(name_1, name);
		}
		count_1 = 0;
	}
	fclose(NAME);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	if (max != 0)
	{
		strncat_1(name_1);
		printf("%s ", name_1);
		return 1;
	}
	else
	{
		return 0;
	}
}
/**
@}
*/
