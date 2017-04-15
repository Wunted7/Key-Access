#include <stdio.h>
#include <allegro5/allegro.h>

int main(int argc, char **argv)
{
	//Переменные
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool user_exit = false;
	const float FPS = 60.0;
	double time_A = 0.0;
	double time_B = 0.0;
	char KEY_CODES[1] = { 'a' };
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
	display = al_create_display(640, 480);
	if (!display) {
		return -1;
	}

	//Инициализация

	al_install_keyboard();
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_init_font_addon();
	al_init_ttf_addon;
	//

	al_start_timer(timer);
	while (!user_exit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			time_A = al_get_time();
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			time_B = al_get_time();
			printf("%c", KEY_CODES[ev.keyboard.keycode-1]);
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				user_exit = true;
			}
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	return 0;
}
