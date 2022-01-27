
#LINUX_VERSION
cmake_minimum_required(VERSION 3.20)
project(cub3d C)

include_directories("includes")
include_directories("mlx")
include_directories("libft")
include_directories("srcs")
include_directories(".obj")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Imlx -lmlx -L/mlx/ -framework OpenGL
-framework AppKit")
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")
set(SRC srcs)
set(LIB libft)

file(GLOB SRCS "${SRC}/*.c")
file(GLOB LIBFT "${LIB}/*.c")

add_executable(cub3d ${SRCS} ${LIBFT})