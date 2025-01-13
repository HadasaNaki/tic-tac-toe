find_package(GTest REQUIRED)

add_executable(tictactoe_board_test board_test.cpp)

target_include_directories(tictactoe_board_test PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(tictactoe_board_test GTest::GTest GTest::Main)

add_test(NAME board_test COMMAND tictactoe_board_test)