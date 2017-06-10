/** @file test_string_functions.c
* @brief Тест функций, работающих со строками
*@author Батов Юрий email - batov1998@list.ru\n
*@author Ильченко Никита email - wunted7@gmail.com
*/
#include "unity.h"
#include "unity_fixture.h"
#include "strncat1.h"
#include "strncat_1.h"
TEST_GROUP(TestString);

TEST_GROUP_RUNNER(TestString)
{
    RUN_TEST_CASE(TestString, namefile_add_1);
    RUN_TEST_CASE(TestString, namefile_add_1_2);
    RUN_TEST_CASE(TestString, namefile_delete_1);
    RUN_TEST_CASE(TestString, namefile_delete_1_2);
}

TEST_SETUP(TestString)
{
}

TEST_TEAR_DOWN(TestString)
{
}
/** \fn TEST(TestString, namefile_add_1)
Тестирование прибавления единицы к концу строки
Сравнивает ожидаемую строку с полученной
*/
TEST(TestString, namefile_add_1)
{
	char a[21]="NAMENAMENAMENAMENAM1", b[20]="NAMENAMENAMENAMENAM";
	strncat1(b);
	TEST_ASSERT_EQUAL_STRING(a, b);
}
/** \fn TEST(TestString, namefile_add_1_2)
Тестирование прибавления единицы к концу строки
Сравнивает ожидаемую строку с полученной
*/

TEST(TestString, namefile_add_1_2)
{
	char a[20]="1", b[20]="";
	strncat1(b);
	TEST_ASSERT_EQUAL_STRING(a, b);
}
/** \fn TEST(TestString, namefile_delete_1)
Тестирование удаления единицы из конца строки
Сравнивает ожидаемую строку с полученной
*/
TEST(TestString, namefile_delete_1)
{
	char a[20]="NAME", b[20]="NAME1";
	strncat_1(b);
	TEST_ASSERT_EQUAL_STRING(a, b);
}
/** \fn TEST(TestString, namefile_delete_1_2)
Тестирование удаления единицы из конца строки
Сравнивает ожидаемую строку с полученной
*/
TEST(TestString, namefile_delete_1_2)
{
	char a[20]="N", b[20]="N1";
	strncat_1(b);
	TEST_ASSERT_EQUAL_STRING(a, b);
}
