cmake_minimum_required(VERSION 3.28)

project(
  optimization-architecture
  VERSION 0.0.1
  LANGUAGES CXX
  )

set (CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)

add_library(lib${PROJECT_NAME} src/cost_functions.cpp)
