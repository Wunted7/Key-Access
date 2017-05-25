#pragma once
/*!
@file delta.h
@{

\brief
Файл погрешностей
*@author Батов Юрий email - batov1998@list.ru\n
*@author Ильченко Никита email - wunted7@gmail.com
*/
/** Отвечает за подсчет погрешностей каждой буквы
    \param[in] count номер буквы
    \param[in] *A указатель на матрицу, содержащую все значения времени нажатой буквы
    \param[in] sr_zn среднее значение времени по данной букве
    \param[out] - выводит погрешность для данной буквы
*/
double delta(int count, double *A, double sr_zn);
/**
@}
*/
