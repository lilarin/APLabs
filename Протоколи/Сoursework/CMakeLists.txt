cmake_minimum_required(VERSION 3.20)
project(Сoursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(Сoursework main.cpp textbox.h button.h shunting_yard.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Сoursework sfml-system sfml-window sfml-graphics sfml-audio)
