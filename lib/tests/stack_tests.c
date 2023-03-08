#include <unity.h>
#include <stack.h>

void setUp() {}
void tearDown() {}

void test_noError_shouldReturn5() {
    int actual = test();
    TEST_ASSERT_EQUAL_INT(5, actual);
} 

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_noError_shouldReturn5);

    return UNITY_END();
}