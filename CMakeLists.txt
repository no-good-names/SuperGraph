cmake_minimum_required(VERSION 3.16)
project(superGraph C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(superGraph ${SOURCES})
target_include_directories(superGraph PRIVATE include)

target_link_libraries(superGraph ${SDL2_LIBRARIES})

