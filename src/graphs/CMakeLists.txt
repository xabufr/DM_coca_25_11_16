add_executable (10K2 10K2.c)
target_link_libraries (10K2 LINK_PUBLIC Core)

add_executable (10K2_print 10K2.c)
target_link_libraries (10K2_print LINK_PUBLIC Print)

add_executable (C10 C10.c)
target_link_libraries (C10 LINK_PUBLIC Core)

add_executable (C10_print C10.c)
target_link_libraries (C10_print LINK_PUBLIC Print)

add_executable (petersen petersen.c)
target_link_libraries (petersen LINK_PUBLIC Core)

add_executable (petersen_print petersen.c)
target_link_libraries (petersen_print LINK_PUBLIC Print)

add_executable (sierp3 sierp3.c)
target_link_libraries (sierp3 LINK_PUBLIC Core)

add_executable (sierp3_print sierp3.c)
target_link_libraries (sierp3_print LINK_PUBLIC Print)

add_executable (kneser62 kneser62.c)
target_link_libraries (kneser62 LINK_PUBLIC Core)

add_executable (kneser62_print kneser62.c)
target_link_libraries (kneser62_print LINK_PUBLIC Print)

add_executable (kneser72 kneser72.c)
target_link_libraries (kneser72 LINK_PUBLIC Core)

add_executable (kneser72_print kneser72.c)
target_link_libraries (kneser72_print LINK_PUBLIC Print)

add_executable (kneser73 kneser73.c)
target_link_libraries (kneser73 LINK_PUBLIC Core)

add_executable (kneser73_print kneser73.c)
target_link_libraries (kneser73_print LINK_PUBLIC Print)

add_executable (kneser83 kneser83.c)
target_link_libraries (kneser83 LINK_PUBLIC Core)

add_executable (kneser83_print kneser83.c)
target_link_libraries (kneser83_print LINK_PUBLIC Print)

add_executable (m47 m47.c)
target_link_libraries (m47 LINK_PUBLIC Core)

add_executable (m47_print m47.c)
target_link_libraries (m47_print LINK_PUBLIC Print)

add_executable (m95 m95.c)
target_link_libraries (m95 LINK_PUBLIC Core)

add_executable (m95_print m95.c)
target_link_libraries (m95_print LINK_PUBLIC Print)

add_executable (chvatal chvatal.c)
target_link_libraries (chvatal LINK_PUBLIC Core)

add_executable (chvatal_print chvatal.c)
target_link_libraries (chvatal_print LINK_PUBLIC Print)

add_executable (golomb golomb.c)
target_link_libraries (golomb LINK_PUBLIC Core)

add_executable (golomb_print golomb.c)
target_link_libraries (golomb_print LINK_PUBLIC Print)

add_executable (moser moser.c)
target_link_libraries (moser LINK_PUBLIC Core)

add_executable (moser_print moser.c)
target_link_libraries (moser_print LINK_PUBLIC Print)

add_executable (hypercube8 hypercube8.c)
target_link_libraries (hypercube8 LINK_PUBLIC Core)

add_executable (hypercube8_print hypercube8.c)
target_link_libraries (hypercube8_print LINK_PUBLIC Print)
