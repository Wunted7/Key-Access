#include "input.h"

int main(void) {//Считает погрешности с динамическим выделением памяти
	setlocale(LC_ALL, "Rus");
	int a;
	int k;
	printf("Здравствуйте ,введите 1 если хотите инициализироваться или 2 если хотите авторизоваться:\n");
	scanf("%i", &a);
	if (a == 1)
	{
		input();
	}

	if(a == 2)
	{
		k = output();
		printf("%i ", k);
		if (k == 1)
		{
			printf("I know you\n");
		}
		else
		{
			printf("I don't know you\n");
		}
	}
	printf("OK\n");
	getchar();
	getchar();
	return 0;
}
