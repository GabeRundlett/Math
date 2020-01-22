
add_library(Math INTERFACE)
target_compile_features(Math INTERFACE cxx_std_17)
target_include_directories(Math INTERFACE ${CMAKE_CURRENT_LIST_DIR})
