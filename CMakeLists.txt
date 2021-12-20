cmake_minimum_required(VERSION 3.10)

project(anim-break VERSION 1.0.0)

add_compile_definitions(ANIM_BREAK_STUDIO_MAJOR_VERSION=1)
add_compile_definitions(ANIM_BREAK_STUDIO_MINOR_VERSION=0)
add_compile_definitions(ANIM_BREAK_STUDIO_PATCH_VERSION=0)

#For testing purpose
add_compile_definitions(REQUIRED_ANIM_BREAK_STUDIO_MAJOR_VERSION=1)
add_compile_definitions(REQUIRED_ANIM_BREAK_STUDIO_MINOR_VERSION=0)
add_compile_definitions(REQUIRED_ANIM_BREAK_STUDIO_PATCH_VERSION=0)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cc")


include_directories("include")

add_subdirectory("third-party/box2d")
add_subdirectory("third-party/doctest")
add_subdirectory("third-party/pugixml")
add_subdirectory("third-party/spdlog")
add_subdirectory("third-party/zlib")

add_subdirectory("unit-test")

add_executable(anim-break "main.cc" ${SOURCES})

target_link_libraries(anim-break box2d zlib spdlog pugixml glfw)