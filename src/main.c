#include <stdio.h>
#include"lib.h"

int main(void) {//¬ывод на консоль предложени€ о регистрации или авторизации
	setlocale(LC_ALL, "Rus");
	int a;
	int k;
	char c;
	do
	{
		printf("«дравствуйте ,введите 1 если хотите инициализироватьс€ или 2 если хотите авторизоватьс€:\n");
		scanf("%i", &a);
		if (a == 1)
		{
			input();
		}

		if (a == 2)
		{
			k = output();
			if (k == 0)
			{
				printf("I don't know you\n");
			}
		}
		getchar();
		printf("\nNext (y/n)? ");
		c = getchar();
	}while (c == 'y');
	return 0;
}
