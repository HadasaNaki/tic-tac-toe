cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for header files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add source files
add_executable(tictactoe src/main.cpp)

# Enable testing
enable_testing()

add_subdirectory(tests)