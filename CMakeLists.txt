cmake_minimum_required(VERSION 3.16)

project("PROJECT-XX")

# define sources, headers paths
file(GLOB HEADERS "headers/*.h")
file(GLOB SOURCES "sources/*.cpp")

# Add libraries
add_subdirectory(libraries/tabulate-master)

add_executable(
    ${PROJECT_NAME} main.cpp
    ${SOURCES}
)
    
# Configure Headers and Sources
target_include_directories(${PROJECT_NAME} PUBLIC headers)

# Configure Headers and Sources
target_include_directories(${PROJECT_NAME} PRIVATE sources)

# Configure C++ Version: 23
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)

# lIBS
target_link_libraries(${PROJECT_NAME} PRIVATE tabulate)