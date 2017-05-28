/*!
@file Stewdent.c
@{

\brief
Файл отвечает за вывод коэффициента Стьюдента
*
*
    *@author Батов Юрий email - batov1998@list.ru\n
    *@author Ильченко Никита email - wunted7@gmail.com
*/
/** По кол-ву значений выводится коэффициент Стьюдента
*/
/**
    ##Функции на вход подается количество значений.
    ##Потом соответсвующему количеству значений выводится коэффициент Стьюдента
*/
double Stewdent(int i)
{
    if (i <= 1)
        return 0;
    else if (i == 2)
        return 12.71;
    else if (i == 3)
        return 4.30;
    else if (i == 4)
        return 3.188;
    else if (i == 5)
        return 2.77;
    else if (i == 6)
        return 2.57;
    else if (i == 7)
        return 2.45;
    else if (i == 8)
        return 2.36;
    else if (i == 9)
        return 2.31;
    else if (i == 10)
        return 2.26;
    else if (i <= 12 && i>10)
        return 2.20;
    else if (i <= 14 && i>12)
        return 2.16;
    else if (i <= 16 && i>14)
        return 2.13;
    else if (i <= 18 && i>16)
        return 2.11;
    else if (i <= 20 && i>18)
        return 2.09;
    else if (i <= 30 && i>20)
        return 2.04;
    else if (i <= 40 && i>30)
         return 2.02;
    else if (i <= 50 && i>40)
         return 2.01;
    else if (i <= 60 && i>50)
         return 2.00;
    else
         return 1.96;
}
/**
@}
*/
