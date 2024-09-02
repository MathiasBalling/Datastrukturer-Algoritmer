add_executable(np np.cpp)
target_link_libraries(np PRIVATE extern)
target_compile_options(np PRIVATE -Wall -Wextra -pedantic)
