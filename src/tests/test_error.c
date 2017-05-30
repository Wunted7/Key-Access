/** @file test_error.c
* @brief Тест функций подсчета погрешностей
*@author Батов Юрий email - batov1998@list.ru\n
*@author Ильченко Никита email - wunted7@gmail.com
*/
#include "unity.h"
#include "unity_fixture.h"
#include "delta.h"
#include "Stewdent.h"
TEST_GROUP(TestErrors);

TEST_GROUP_RUNNER(TestErrors)
{
    	RUN_TEST_CASE(TestErrors, delta1);
      RUN_TEST_CASE(TestErrors, delta2);
      RUN_TEST_CASE(TestErrors, delta3);
    	RUN_TEST_CASE(TestErrors, stewdent1);
      RUN_TEST_CASE(TestErrors, stewdent2);
      RUN_TEST_CASE(TestErrors, stewdent3);
}

TEST_SETUP(TestErrors)
{
}

TEST_TEAR_DOWN(TestErrors)
{
}
/** \fn TEST(TestErrors, delta1)
Тестирование подсчета погрешности
Сравнивает две переменных, подсчитанных функцией и вручную
*/
TEST(TestErrors, delta1)
{
	double A[]={1.0, 2.0};
	double a = 6.355;
	double b = delta(2, A, 1.5);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
/** \fn TEST(TestErrors, delta2)
Тестирование подсчета погрешности
Сравнивает две переменных, подсчитанных функцией и вручную
*/
TEST(TestErrors, delta2)
{
	double A[]={1.0, 2.0, 3.0};
	double a = sqrt(2.0/6.0)*4.3;
	double b = delta(3, A, 2);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
/** \fn TEST(TestErrors, delta3)
Тестирование подсчета погрешности
Сравнивает две переменных, подсчитанных функцией и вручную
*/
TEST(TestErrors, delta3)
{
	double A[]={1.0, 3.0};
	double a = sqrt(2.0/2.0)*12.71;
	double b = delta(2, A, 2);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
/** \fn TEST(TestErrors, stewdent1)
Тестирование правильности вывода коэффициента Стьюдента
Сравнивает ожидаемый коэффициент и коэффициент, полученный функцией
*/
TEST(TestErrors, stewdent1)
{
	double a = 12.71;
	double b = Stewdent(2);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
/** \fn TEST(TestErrors, stewdent2)
Тестирование правильности вывода коэффициента Стьюдента
Сравнивает ожидаемый коэффициент и коэффициент, полученный функцией
*/
TEST(TestErrors, stewdent2)
{
	double a = 1.96;
	double b = Stewdent(61);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
/** \fn TEST(TestErrors, stewdent3)
Тестирование правильности вывода коэффициента Стьюдента
Сравнивает ожидаемый коэффициент и коэффициент, полученный функцией
*/
TEST(TestErrors, stewdent3)
{
	double a = 2.26;
	double b = Stewdent(10);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
