#include "lib.h"
/*!
@file delta.c
@{

\brief
Файл отвечает за работу с погрешностями
*
*
    *@author Батов Юрий \n
    *@author Ильченко Никита
*/
/**Отвечает за подсчет погрешностей каждой введенной буквы
*/
/**
    ##Функции на вход подается среднее значение введенной буквы
    ##Возвращает погрешность всех значений одной буквы
*/
double delta(int count, double *A, double sr_zn) {
	int j;
	double sumd = 0.0, disp;
	for (j = 0; j<count; ++j) {
		sumd += (A[j] - sr_zn)*(A[j] - sr_zn);
	}
	disp = sqrt(sumd / (count*(count - 1)));
	return disp*Stewdent(count);
}
/**
@}
*/
