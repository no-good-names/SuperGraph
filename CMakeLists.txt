cmake_minimum_required(VERSION 3.16)
project(superGraph C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 QUIET)

if(SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
else()
    message(STATUS "SDL2 wasn't found, please install")
endif()

set(LIBS ${LIBS} ${SDL2_LIBRARIES} m)

add_executable(superGraph
        src/main.c
        src/cmaths.c
        src/scene.c
        src/renderer.c
)
target_include_directories(superGraph PRIVATE include)

target_link_libraries(superGraph ${LIBS})
