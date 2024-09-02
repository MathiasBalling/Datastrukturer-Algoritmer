add_executable(1 1.cpp)
target_link_libraries(1 PRIVATE extern)
target_compile_options(1 PRIVATE -Wall -Wextra -pedantic)
