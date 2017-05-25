#include "lib.h"
/*!
@file strncat_1.c
@{

\brief
Файл отвечает за работу с именами файлов
*
*
    *@author Батов Юрий email - batov1998@list.ru\n
    *@author Ильченко Никита email - wunted7@gmail.com
*/
/** Удаляет 1 из имени файла
*/
/**
    ##Функции на вход подается имя файла
    ##В конце функции имя файла без 1
*/
void strncat_1(char *stroka)
{
	int i = 0;
	while (stroka[i] != '\0')
    {
		i++;
	}
	i--;
	stroka[i] = '\0';
}
/**
@}
*/
