# Utils Dir #

#####################
# Definiton Options #

#####################

add_definitions()

add_library(coreutils OBJECT
    djb2_hash.c
)

add_subdirectory(tests)