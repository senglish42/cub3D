cmake_minimum_required(VERSION 3.20)
project(cub3d C)

include_directories("/Users/senglish/cub3d/includes/")
include_directories("/Users/senglish/cub3d/mlx/")

set(CMAKE_C_STANDARD 99)

add_executable(cub3d srcs/main.c includes/cub3D.h)