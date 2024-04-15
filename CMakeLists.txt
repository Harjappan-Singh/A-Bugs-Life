cmake_minimum_required(VERSION 3.27)
project(Bug_Life_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bug_Life_Project main.cpp
        Bug.cpp
        Bug.h
        Crawler.cpp
        Crawler.h)
