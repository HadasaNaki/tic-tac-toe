find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(board_test board_test.cpp)
target_link_libraries(board_test ${GTEST_LIBRARIES} pthread)

add_test(NAME board_test COMMAND board_test)
