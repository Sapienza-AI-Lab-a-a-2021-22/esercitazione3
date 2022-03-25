cmake_minimum_required(VERSION 2.8)

project(ai-lab_es3)

set(CMAKE_CXX_FLAGS "-Wall -fdiagnostics-color=always -std=c++11 -pthread -g -march=native -fPIC")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/)

add_library(uwimg++ SHARED
            src/utils.cpp
            src/utils.h
            src/image.h
            src/load_image.cpp
            src/stb_image.h
            src/stb_image_write.h
            src/process_image.cpp
            src/resize_image.cpp
            src/filter_image.cpp

        src/edge_detection.cpp)

link_libraries(uwimg++ m stdc++)

add_executable(test2 src/test/test2.cpp)


