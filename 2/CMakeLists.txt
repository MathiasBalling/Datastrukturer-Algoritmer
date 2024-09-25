add_executable(2 2.cpp)
target_link_libraries(2 PRIVATE extern)
target_compile_options(2 PRIVATE -Wall -Wextra -pedantic)
