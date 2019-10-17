file(GLOB_RECURSE MATH_SOURCES "src/*.cpp" "src/*.hpp")
add_library(math STATIC ${MATH_SOURCES})
