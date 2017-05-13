#define UNITY_INCLUDE_DOUBLE

#include "unity.h"
#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(TestString);
    RUN_TEST_GROUP(TestErrors);
}

int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
