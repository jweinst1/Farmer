# Core Farmer Library #

add_subdirectory(stringtool)

# Farmer Static Library #
add_library(FarmerStat STATIC
     $<TARGET_OBJECTS:stringtool>
)

# Farmer Shared Library #
add_library(FarmerShared SHARED
     $<TARGET_OBJECTS:stringtool>
)



