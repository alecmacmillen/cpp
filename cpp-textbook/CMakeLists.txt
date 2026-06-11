cmake_minimum_required(VERSION 3.20)

project(cpp-textbook) # Update this for new project names

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Update the project name in this call as well
add_executable(cpp-textbook
    src/main.cpp
)