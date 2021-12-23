cmake_minimum_required(VERSION 3.10)

project(unit-test)
include_directories("third-party/doctest")


set(IMGUI_SOURCES2 "../third-party/imgui/imgui.cpp" "../third-party/imgui/imgui_demo.cpp"
	"../third-party/imgui/imgui_draw.cpp" "../third-party/imgui/imgui_tables.cpp"
	"../third-party/imgui/imgui_widgets.cpp" "../third-party/imgui/backends/imgui_impl_glfw.cpp"
	"../third-party/imgui/backends/imgui_impl_opengl3.cpp")

add_executable(
	unit-test
	${SOURCES}
	${IMGUI_SOURCES2}
	sample_test.cc
	version_check_test.cc
	window_manager_test.cc
)

set_target_properties(unit-test PROPERTIES
	CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(unit-test "doctest_with_main" glfw box2d pugixml spdlog opengl32)