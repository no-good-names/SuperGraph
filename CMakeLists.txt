cmake_minimum_required(VERSION 3.16)
project(SuperGraph C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 QUIET)

if(SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
else()
    message(STATUS "SDL2 wasn't found, please install")
endif()

set(LIBS ${LIBS} ${SDL2_LIBRARIES} m)

add_executable(SuperGraph
        src/main.c
        src/gfx/math/cmaths.c
        src/gfx/math/cmaths.h
        src/gfx/scene.c
        src/gfx/scene.h
        src/gfx/gfx.h
        src/gfx/light.c
        src/gfx/light.h
        src/gfx/rays.c
        src/gfx/rays.h
        src/gfx/camera.h
        src/gfx/camera.c
)
target_link_libraries(SuperGraph ${LIBS})
