cmake_minimum_required(VERSION 3.10)

project(anim-break)

add_subdirectory("third-party/doctest")
add_subdirectory("third-party/pugixml")
add_subdirectory("third-party/spdlog")
add_subdirectory("third-party/zlib")
add_subdirectory("third-party/glfw")

add_subdirectory("unit-test")

add_executable(anim-break "main.cc")

target_link_libraries(anim-break zlib spdlog pugixml)