find_package(fmt)
if(NOT fmt_FOUND)
  message(STATUS "fmt not found")
else()
  message(STATUS "fmt found via find_package")
endif()

add_library(extern INTERFACE)
target_link_libraries(extern INTERFACE fmt::fmt)
