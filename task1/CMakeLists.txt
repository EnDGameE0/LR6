cmake_minimum_required(VERSION 3.10)
project(FindSmallestGroup)

# Установите минимальную версию CMake
#set(CMAKE_CXX_STANDARD 11)
#et(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавьте исходные файлы
#set(SOURCES   task_1.cpp)

# Добавьте исполняемый файл
add_executable(FindSmallestGrou task_1.cpp)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
   target_compile_options(FindSmallestGroup PRIVATE -fsanitize=thread -fsanitize=address)
   target_link_libraries(FindSmallestGroup PRIVATE -fsanitize=thread -fsanitize=address)
endif()