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
	double sr_zn = 0.0 ,disp = 0.0,t = 0.0,k = 0.0;
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
