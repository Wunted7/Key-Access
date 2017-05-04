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

int main(void) { //Считает погрешности с динамическим выделением памяти
	input();
	printf("OK");
	return 0;

}
