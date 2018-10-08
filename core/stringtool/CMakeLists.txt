# String Tools Dir #

#####################
# Definiton Options #
# 1. CHAR_O_STREAM_EXPAND_DOUBLE
#####################

add_definitions()

add_library(stringtool OBJECT
    strfind.c
    char_out_stream.c
)

add_subdirectory(tests)