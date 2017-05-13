#include "unity.h"
#include "unity_fixture.h"
#include "strncat1.h"
#include "strncat_1.h"
TEST_GROUP(TestString);

TEST_GROUP_RUNNER(TestString)
{
    RUN_TEST_CASE(TestString, namefile_add_1);
    RUN_TEST_CASE(TestString, namefile_delete_1);
}

TEST_SETUP(TestString)
{
}

TEST_TEAR_DOWN(TestString)
{
}

TEST(TestString, namefile_add_1)
{
	char a[20]="NAME1", b[20]="NAME"; 
	strncat1(b);
	TEST_ASSERT_EQUAL_STRING(a, b);
}
TEST(TestString, namefile_delete_1)
{
	char a[20]="NAME", b[20]="NAME1";
	strncat_1(b);
	TEST_ASSERT_EQUAL_STRING(a, b);
}
