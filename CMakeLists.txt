cmake_minimum_required(VERSION 3.27)

project(15game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB sources src/*)

add_executable(${PROJECT_NAME} ${sources})
