cmake_minimum_required(VERSION 3.12)

project(Math VERSION 1.0.0)

if (NOT TARGET Math)
    add_subdirectory(src)
endif()
