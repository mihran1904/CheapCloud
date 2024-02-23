# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/enums_struct_exmpl_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/enums_struct_exmpl_autogen.dir/ParseCache.txt"
  "enums_struct_exmpl_autogen"
  )
endif()
