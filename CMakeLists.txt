cmake_minimum_required(VERSION 3.13)
project(programming_2_coursework_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(programming_2_coursework_2 main.cpp Duration.cpp Duration.h Track.cpp Track.h Album.cpp Album.h Collection.cpp Collection.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/albums.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})