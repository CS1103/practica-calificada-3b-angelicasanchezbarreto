cmake_minimum_required(VERSION 3.15)
project(pc3b)

set(CMAKE_CXX_STANDARD 17)
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -Wextra")
endif()

add_executable(pc3b main.cpp)