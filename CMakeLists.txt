cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 99)

file(GLOB C_HEADERS "minilibx_macos/*.h")

add_definitions(-Wall -Werror -Wextra)

add_executable(fdf main.c fdf.h
        put_line.c)

target_link_libraries(${PROJECT_NAME}
        "mlx"
        "-framework OpenGL"
        "-framework AppKit")