cmake_minimum_required(VERSION 3.28)

project(
  optimization-architecture
  VERSION 0.0.1
  LANGUAGES CXX
  )

set (CMAKE_CXX_STANDARD 17)
add_compile_options(-Werror -Wall -Wextra -Wpedantic)

set(SRC_FILES 
    src/cost_functions.cpp
)

add_library(${PROJECT_NAME} SHARED
    ${SRC_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    include
)
