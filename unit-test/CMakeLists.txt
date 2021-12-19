cmake_minimum_required(VERSION 3.10)

project(unit-test)
include_directories("third-party/doctest")

add_executable(
	unit-test 
	"sample_test.cc"
)

set_target_properties(unit-test PROPERTIES
	CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(unit-test "doctest_with_main")