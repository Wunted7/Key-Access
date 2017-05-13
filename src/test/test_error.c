#include "unity.h"
#include "unity_fixture.h"
#include "delta.h"
#include "Stewdent.h"
TEST_GROUP(TestErrors);

TEST_GROUP_RUNNER(TestErrors)
{
    	RUN_TEST_CASE(TestErrors, delta);
    	RUN_TEST_CASE(TestErrors, stewdent);
}

TEST_SETUP(TestErrors)
{
}

TEST_TEAR_DOWN(TestErrors)
{
}

TEST(TestErrors, delta)
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
TEST(TestErrors, stewdent)
{
	double a = 12.71;
	double b = Stewdent(2);
	TEST_ASSERT_EQUAL_FLOAT(a, b);
}
