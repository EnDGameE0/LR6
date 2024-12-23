cmake_minimum_required(VERSION 3.10)
project(Sosal?)

add_executable(Task3 task_3.cpp)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
   target_compile_options(FindSmallestGroup PRIVATE -fsanitize=thread -fsanitize=address)
   target_link_libraries(FindSmallestGroup PRIVATE -fsanitize=thread -fsanitize=address)
endif()