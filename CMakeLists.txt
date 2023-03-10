cmake_minimum_required(VERSION 3.25)
project(App)

enable_testing()
include(CTest)
add_subdirectory(app)
add_subdirectory(lib)

add_subdirectory(external)