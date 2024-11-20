add_executable(port2_1 port_1.cpp)
target_compile_options(port_1 PRIVATE -Wall -Wextra -pedantic)

add_executable(port2_2 port_2.cpp BinarySearchTree.cpp)
target_compile_options(port2_2 PRIVATE -Wall -Wextra -pedantic)
