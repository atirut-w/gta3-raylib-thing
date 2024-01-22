add_library("rwloader" STATIC
    "src/chunk.cpp"
)
target_include_directories("rwloader" PUBLIC "include")
