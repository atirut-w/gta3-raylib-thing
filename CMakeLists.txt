cmake_minimum_required(VERSION 3.22)

# Libraries
add_subdirectory("3rd/raylib")

add_executable("gta3r"
    "src/main.cpp"
)
target_include_directories("gta3r" PRIVATE "include")
target_link_libraries("gta3r" PRIVATE "raylib")
