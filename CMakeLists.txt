cmake_minimum_required(VERSION 3.17)
project(game_demo)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB source_files "*.cpp")

add_executable(game_demo ${source_files})

target_include_directories(game_demo PRIVATE include)
target_link_libraries(game_demo sfml-system sfml-window sfml-graphics)