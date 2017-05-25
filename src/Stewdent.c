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
	if (i == 2)
		return 12.71;
	if (i == 3)
		return 4.30;
	if (i == 4)
		return 3.188;
	if (i == 5)
		return 2.77;
	if (i == 6)
		return 2.57;
	if (i == 7)
		return 2.45;
	if (i == 8)
		return 2.36;
	if (i == 9)
		return 2.31;
	if (i == 10)
		return 2.26;
	if (i <= 12 && i>10)
		return 2.20;
	if (i <= 14 && i>12)
		return 2.16;
	if (i <= 16 && i>14)
		return 2.13;
	if (i <= 18 && i>16)
		return 2.11;
	if (i <= 20 && i>18)
		return 2.09;
	if (i <= 30 && i>20)
		return 2.04;
	if (i <= 40 && i>30)
		 return 2.02;
	if (i <= 50 && i>40)
		 return 2.01;
	if (i <= 60 && i>50)
		 return 2.00;
	if (i > 60)
		 return 1.96;
}
/**
@}
*/
