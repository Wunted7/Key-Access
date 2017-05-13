#include "lib.h"

void strncat_1(char *a)
{
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	i--;
	a[i] = '\0';
}