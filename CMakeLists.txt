cmake_minimum_required(VERSION 3.22)

project(15game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB sources src/*)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

add_executable(${PROJECT_NAME} ${sources}
        src/game.cpp
        src/game.h)

# ncurses
set(CURSES_NEED_NCURSES TRUE)

find_package(Curses REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${CURSES_CFLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
