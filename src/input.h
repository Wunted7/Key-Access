#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include <locale.h>
#include <allegro5/allegro_native_dialog.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro_font.h>
#define MAX_SIZE 50
#define MAX_LETTER 26


double A[MAX_LETTER][MAX_SIZE];


int input();
int output();
void strncat1(char *a);
double Stewdent(int i);
