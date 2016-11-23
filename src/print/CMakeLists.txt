add_library (Print main.c)

target_include_directories (Print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../graphs ${CMAKE_CURRENT_SOURCE_DIR})
