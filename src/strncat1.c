#include "lib.h"

void strncat1(char *a)
{
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	char k = '1';
	a[i] = k;
	i++;
	a[i] = '\0';
}