# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/arrays_string_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/arrays_string_autogen.dir/ParseCache.txt"
  "arrays_string_autogen"
  )
endif()
