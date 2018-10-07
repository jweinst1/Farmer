# Cmd line app directory for Farmer #

# Not yet implemented #


add_executable(farm_cmd main.c)

target_include_directories(farm_cmd
  PUBLIC
      ${PROJECT_SOURCE_DIR}/core
)

target_link_libraries(farm_cmd FarmerCore)