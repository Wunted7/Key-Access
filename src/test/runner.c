#include "unity.h"
#include "unity_fixture.h"
/** @file runner.c
* @brief Функция запуска всех тестов
*@author Батов Юрий email - batov1998@list.ru\n
*@author Ильченко Никита email - wunted7@gmail.com
*/
static void RunAllTests(void)
{
    RUN_TEST_GROUP(TestString);
    RUN_TEST_GROUP(TestErrors);
}

int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
