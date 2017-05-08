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
	int a;
	int k;
	printf("Здравствуйте ,введите 1 если хотите инициализироваться или 2 если хотите авторизоваться:\n");
	scanf("%i", &a);
	switch (a)
	{
	case 1:
		input();
		break;
	case 2:
		k = output();
		if (!k) {
			printf("I know you\n");
		}
		else {
			printf("I don't know you\n");
		}
		break;
	}
	printf("OK\n");
	getchar();
	getchar();
	return 0;
}
