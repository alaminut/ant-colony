cmake_minimum_required(VERSION 3.17)
project(game_demo)

set(CMAKE_CXX_STANDARD 17)

if(MSVC OR WIN32)
    set(SFML_DIR "c:/dev/lib/sfml-2.5.1-msvc15/lib/cmake/sfml")
endif()

set(SFML_STATIC_LIBRARIES TRUE)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB source_files "*.cpp")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
add_executable(game_demo ${source_files})

target_include_directories(game_demo PRIVATE include)
target_link_libraries(game_demo sfml-system sfml-window sfml-graphics)