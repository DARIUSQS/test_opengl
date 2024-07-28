cmake_minimum_required(VERSION 3.6)

project(imgui)

add_library(imgui)

target_sources(imgui PRIVATE
    "src/imgui/imgui.cpp"
    "src/imgui/imgui_demo.cpp"
    "src/imgui/imgui_draw.cpp"
    "src/imgui/imgui_tables.cpp"
    "src/imgui/imgui_widgets.cpp"
    "src/imgui/backends/imgui_impl_glfw.cpp"
    "src/imgui/backends/imgui_impl_opengl3.cpp"
)
target_include_directories(imgui PUBLIC src)

target_link_libraries(imgui PUBLIC glfw glad)
