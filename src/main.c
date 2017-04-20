#include <stdio.h>
#include <allegro5/allegro.h>
#include <locale.h>
#include <allegro5/allegro_native_dialog.h>


int main(int argc, char **argv)
{
	setlocale(0, "russian");
	//Переменные
	ALLEGRO_TEXTLOG *textlog;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool user_exit = false;
	const float FPS = 60.0;
	double time_A = 0.0;
	double time_B = 0.0;
	char KEY_CODES[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', };
	KEY_CODES[74] =  ' ' ;
	//
	if (!al_init()) {
		return -1;
	}

	if (!al_install_keyboard()) {
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		return -1;
	}
	al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED);
	display = al_create_display(800, 480);
	if (!display) {
		return -1;
	}

	//Инициализация

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//

	//al_start_timer(timer);
	printf("Здравствуйте, приветствуем Вас в программе Key-Access\n");
	printf("Для начала работы, прошу ввести вас данную фразу\n");
	while (!user_exit) {
		system("cmd.exe");
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			time_A = al_get_time();
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			time_B = al_get_time();
			printf("%c ", KEY_CODES[ev.keyboard.keycode - 1]);
			printf("%f\n", time_B - time_A);
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				user_exit = true;
			}
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			user_exit = true;
		}
		if ((time_B - time_A) > 1.0) {
			switch (al_show_native_message_box(al_get_current_display(), "Key-Access", "question", "I don't you know. Will you get access to this programm?", NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL))
			{
			case 0:
				user_exit = true;
				break;
			case 1:
				user_exit = true;
				break;
			}
		}

	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	return 0;
}
