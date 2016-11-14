add_library (Core main.c)

target_include_directories (Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../graphs ${CMAKE_CURRENT_SOURCE_DIR})
