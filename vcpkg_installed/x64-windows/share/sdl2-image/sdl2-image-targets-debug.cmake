#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL2::SDL2_image" for configuration "Debug"
set_property(TARGET SDL2::SDL2_image APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL2::SDL2_image PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/SDL2_image.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "SDL2::SDL2;${_IMPORT_PREFIX}/debug/lib/libpng16d.lib;${_IMPORT_PREFIX}/debug/lib/zlibd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/SDL2_image.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SDL2::SDL2_image )
list(APPEND _IMPORT_CHECK_FILES_FOR_SDL2::SDL2_image "${_IMPORT_PREFIX}/debug/lib/SDL2_image.lib" "${_IMPORT_PREFIX}/debug/bin/SDL2_image.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
