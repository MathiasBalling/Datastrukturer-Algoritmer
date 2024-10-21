#include "BinarySearchTree.h"
#include <print>

int main(int argc, char *argv[]) {
  std::array<int, 10> inputs = {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};
  auto tree = BinarySearchTree();
  for (int i : inputs) {
    tree.insert(i);
  }
  std::println("In Order");
  tree.printTreeInOrder();
  std::println("Pre Order");
  tree.printTreePreOrder();
  std::println("Post Order");
  tree.printTreePostOrder();
  std::println("Level Order");
  tree.printTreeLevelOrder();

  return 0;
}
