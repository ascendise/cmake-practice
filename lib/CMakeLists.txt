add_library(Stack stack.c)
target_include_directories(Stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(CTest)
enable_testing()
add_subdirectory(tests)