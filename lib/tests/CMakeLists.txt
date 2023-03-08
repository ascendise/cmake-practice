add_executable(Stack_tests stack_tests.c)
target_link_libraries(Stack_tests Unity Stack)

add_test(stack_test_suite Stack_tests)