
### Pulls in stringtool directory ###
include_directories(
    ${PROJECT_SOURCE_DIR}/core/testinclude
	${CMAKE_CURRENT_SOURCE_DIR}/..
)


### Testing Macro ###
macro(create_stringtool_test file_name)
add_executable(${file_name} $<TARGET_OBJECTS:stringtool> ${file_name}.c)
add_test(${file_name} ${file_name})
endmacro()

### Tests begin here ###
create_stringtool_test(test_strfind)
create_stringtool_test(test_char_out_stream)