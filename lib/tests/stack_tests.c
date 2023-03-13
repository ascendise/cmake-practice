#include <unity.h>
#include <stack.h>

void setUp() {}
void tearDown() {}

void test_pushPop_noExceptions_shouldReturnSameElementWhenPushingAndPopping() {
    //Arrange
    Stack* stack = stack_init();
    //Act
    int value = 5;
    stack_push(stack, value);
    int result = 0;
    int error = stack_pop(stack, &result);
    //Assert
    TEST_ASSERT_EQUAL_INT(5, result);
    TEST_ASSERT_EQUAL_INT(STACK_NO_ERROR, error);
    stack_free(stack);
}

void test_pop_emptyStackPopped_shouldReturnErrorWhenTryingToPopEmptyStack() {
    //Arrange
    Stack* stack = stack_init();
    //Act
    int result = 0;
    int error = stack_pop(stack, &result);
    //Assert
    TEST_ASSERT_EQUAL_INT(STACK_EMPTY_ERROR, error);
    TEST_ASSERT_EQUAL_INT(0, result);
    stack_free(stack);
}

void test_free_freeBigStack_shouldNotErr() {
    //Arrange
    Stack* stack = stack_init();
    //Act
    for(int i = 0; i < 100; i++) {
        stack_push(stack, i);
    }
    stack_free(stack);
    //Assert
    TEST_PASS();
}

void test_free_freeEmptyStack_shouldNotErr() {
    //Arrange
    Stack* stack = stack_init();
    //Act
    stack_free(stack);
    //Assert
    TEST_PASS();
}

void test_length_noExceptions_shouldReturnCorrectLength() {
    //Arrange
    Stack* stack = stack_init();
    stack_push(stack, 1);
    stack_push(stack, 1);
    //Act
    int len = stack_length(stack);
    stack_free(stack);
    //Assert
    TEST_ASSERT_EQUAL_INT(2, len);
}

void test_peek_noExceptions_shouldReturnLastElementWithoutRemovingIt() {
    //Arrange
    Stack* stack = stack_init();
    stack_push(stack, 101);
    //Act
    int value;
    int error = stack_peek(stack, &value);
    //Assert
    TEST_ASSERT_EQUAL_INT(101, value);
    TEST_ASSERT_EQUAL_INT(STACK_NO_ERROR, error);
    TEST_ASSERT_EQUAL_INT(1, stack_length(stack));
    stack_free(stack);
}

void test_peek_stackEmpty_shouldReturnError() {
    //Arrange
    Stack* stack = stack_init();
    //Act
    int value;
    int error = stack_peek(stack, &value);
    //Assert
    TEST_ASSERT_EQUAL_INT(STACK_EMPTY_ERROR, error);
    TEST_ASSERT_EQUAL_INT(0, stack_length(stack));
    stack_free(stack);
}

void test_fail() {
    TEST_FAIL();
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_pushPop_noExceptions_shouldReturnSameElementWhenPushingAndPopping);
    RUN_TEST(test_pop_emptyStackPopped_shouldReturnErrorWhenTryingToPopEmptyStack);
    RUN_TEST(test_free_freeBigStack_shouldNotErr);
    RUN_TEST(test_free_freeEmptyStack_shouldNotErr);
    RUN_TEST(test_length_noExceptions_shouldReturnCorrectLength);
    RUN_TEST(test_peek_noExceptions_shouldReturnLastElementWithoutRemovingIt);
    RUN_TEST(test_peek_stackEmpty_shouldReturnError);
    RUN_TEST(test_fail);
    return UNITY_END();
}