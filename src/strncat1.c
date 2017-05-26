#include "lib.h"
/*!
@file strncat1.c
@{

\brief
Файл отвечает за работу с именами файлов
*
*
    *@author Батов Юрий email - batov1998@list.ru\n
    *@author Ильченко Никита email - wunted7@gmail.com
*/
/** Добавляет 1 в имя файла
*/
/**
    ##Функции на вход подается имя файла
    ##В конце функции имя файла с 1
*/
void strncat1(char *stroka)
{
    unsigned int i = 0;
    while (stroka[i] != '\0')
    {
        i++;
    }
    char k = '1';
    stroka[i] = k;
    i++;
    stroka[i] = '\0';
}
/**
@}
*/
