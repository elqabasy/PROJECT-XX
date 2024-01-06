cmake_minimum_required(VERSION 3.16)

project("PROJECT-XX")

add_executable(
    ${PROJECT_NAME} main.cpp
)

# Configure Headers and Sources
target_include_directories(${PROJECT_NAME} PUBLIC headers)

# Configure Headers and Sources
target_include_directories(${PROJECT_NAME} PUBLIC sources)

# Configure C++ Version: 23
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)