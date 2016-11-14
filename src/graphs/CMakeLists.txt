add_executable (10K2 10K2.c)
target_link_libraries (10K2 LINK_PUBLIC Core)

add_executable (C10 C10.c)
target_link_libraries (C10 LINK_PUBLIC Core)

add_executable (petersen petersen.c)
target_link_libraries (petersen LINK_PUBLIC Core)

add_executable (sierp3 sierp3.c)
target_link_libraries (sierp3 LINK_PUBLIC Core)
