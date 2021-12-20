cmake_minimum_required(VERSION 3.10)

project(anim-break VERSION 1.0.0)

add_compile_definitions(ANIM_BREAK_STUDIO_MAJOR_VERSION=1)
add_compile_definitions(ANIM_BREAK_STUDIO_MINOR_VERSION=0)
add_compile_definitions(ANIM_BREAK_STUDIO_PATCH_VERSION=0)

#For testing purpose
add_compile_definitions(REQUIRED_ANIM_BREAK_STUDIO_MAJOR_VERSION=1)
add_compile_definitions(REQUIRED_ANIM_BREAK_STUDIO_MINOR_VERSION=0)
add_compile_definitions(REQUIRED_ANIM_BREAK_STUDIO_PATCH_VERSION=0)


#Unsupported API Defined Here
add_compile_definitions(anim_log__load_levels_const_int_argc__const_char_pp_argv)
#End of Unsupported API

include_directories("include" 
	"third-party/spdlog/include" 
	"third-party/imgui" 
	"third-party/imgui/backends"
	"third-party/glfw/include"
	)


file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cc")

set(IMGUI_SOURCES "third-party/imgui/imgui.cpp" "third-party/imgui/imgui_demo.cpp"
	"third-party/imgui/imgui_draw.cpp" "third-party/imgui/imgui_tables.cpp"
	"third-party/imgui/imgui_widgets.cpp" "third-party/imgui/backends/imgui_impl_glfw.cpp"
	"third-party/imgui/backends/imgui_impl_opengl3.cpp")


add_subdirectory("third-party/box2d")
add_subdirectory("third-party/doctest")
add_subdirectory("third-party/pugixml")
add_subdirectory("third-party/spdlog")
add_subdirectory("third-party/zlib")

add_subdirectory("unit-test")

add_executable(anim-break "main.cc" ${SOURCES})

target_link_libraries(anim-break box2d zlib spdlog pugixml glfw)