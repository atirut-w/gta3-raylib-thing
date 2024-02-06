add_library("rwloader" STATIC
    "src/chunk.cpp"
    "src/texture_dict.cpp"
    "src/struct.cpp"
    "src/raster.cpp"
)
target_include_directories("rwloader" PUBLIC "include")
