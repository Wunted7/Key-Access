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

int main(void) {//Считает погрешности с динамическим выделением памяти
	setlocale(LC_ALL, "Rus");
	char a;
	printf("Здравсивуйте ,введите 1 если хотите инициализированься и 2 если хотите авторизоваться: ?");
	scanf("%c", &a);
	if (a == '1')
	{
		input();
	}
	//if (a == '2') \
	{\
		output();\
	}
	printf("OK");
	return 0;

}
