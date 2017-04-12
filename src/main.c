#include <stdio.h> 
#include <allegro5/allegro.h> 
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h> 

const float FPS = 60;
const int SCREEN_W = 840;
const int SCREEN_H = 580;

int main(int argc, char **argv)
{
	//Переменные
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool user_exit = false;
	const float FPS = 60.0;
	//
	if (!al_init()) {
		return -1;
	}
	display = al_create_display(SCREEN_W, SCREEN_H);

	if (!display) {
		return -1;
	}

	if (!al_install_keyboard()) {
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		return -1;
	}

	//Инициализация
	al_install_keyboard();
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_init_font_addon();
	al_init_ttf_addon;
	//	
	
	ALLEGRO_FONT *font = al_load_font("C:\Windows\Fonts\Arial.ttf", 20, 0);
	al_start_timer(timer);
	while (!user_exit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_A) {
				al_stop_timer(timer);
				al_draw_textf(font, al_map_rgb(0, 0, 255), 420.0, 290.0, ALLEGRO_ALIGN_CENTER, const (char)al_get_timer_count(timer));
				}
			}
		
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				user_exit = true;
			}
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	al_destroy_timer(timer);
	return 0;
}
