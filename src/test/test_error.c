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

TEST(TestErrors, delta1)
{
	double A[]={1.0, 2.0};
	int j;
	double sumd = 0.0, disp;
	for (j = 0; j<2; ++j){
		sumd += (A[j] - 1.5)*(A[j] - 1.5);
	}
	disp = sqrt(sumd / (2*(2 - 1)));
	double a = disp*Stewdent(2);
	double b = delta(2, A, 1.5);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
TEST(TestErrors, delta2)
{
	double A[]={1.0, 2.0, 3.0};
	int j;
	double sumd = 0.0, disp;
	for (j = 0; j<3; ++j){
		sumd += (A[j] - 2)*(A[j] - 2);
	}
	disp = sqrt(sumd / (3*(3 - 1)));
	double a = disp*Stewdent(3);
	double b = delta(3, A, 2);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
TEST(TestErrors, delta3)
{
	double A[]={1.0, 3.0};
	int j;
	double sumd = 0.0, disp;
	for (j = 0; j<2; ++j){
		sumd += (A[j] - 2)*(A[j] - 2);
	}
	disp = sqrt(sumd / (2*(2 - 1)));
	double a = disp*Stewdent(2);
	double b = delta(2, A, 2);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
TEST(TestErrors, stewdent1)
{
	double a = 12.71;
	double b = Stewdent(2);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
TEST(TestErrors, stewdent2)
{
	double a = 1.96;
	double b = Stewdent(61);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
TEST(TestErrors, stewdent3)
{
	double a = 2.26;
	double b = Stewdent(10);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
