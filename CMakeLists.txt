cmake_minimum_required(VERSION 3.10)
project(Render-Engine-C VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Flags d'optimisation de niveau production
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -O3 -march=native -flto")

add_executable(${PROJECT_NAME} src/main.c src/image.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
