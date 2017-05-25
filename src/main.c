#include <stdio.h>
#include"lib.h"

int main(void) {//вывод на консоль предложения об авторизации и регистрации
	setlocale(LC_ALL, "Rus");
    unsigned int a;
	int k;
	char c;
	do
	{
		printf("Здравствуйте ,введите 1 если хотите инициализироваться или 2 если хотите авторизоваться:\n");
		scanf("%i", &a);
		if(a != 1 && a != 2)
        {
            continue;
        }
		else if (a == 1)
		{
			input();
		}
		else (a == 2)
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
