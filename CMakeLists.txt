cmake_minimum_required (VERSION 2.8.11)
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project (DM_CoCa)


add_subdirectory (src/core)
add_subdirectory (src/graphs)
add_subdirectory (src/print)
