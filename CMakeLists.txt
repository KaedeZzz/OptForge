cmake_minimum_required(VERSION 3.20)
project(OptForge VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_library(optforge STATIC
    src/quadratic.cpp
)

target_include_directories(optforge PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

enable_testing()

add_executable(test_quadratic tests/test_quadratic.cpp)
target_link_libraries(test_quadratic PRIVATE optforge)

add_test(NAME quadratic COMMAND test_quadratic)