#include "BinarySearchTree.h"
#include <print>

int main() {
  std::vector<int> inputs = {45, 15, 79, 10, 20, 55, 90, 12, 50};
  auto tree = BinarySearchTree();
  for (int i : inputs) {
    tree.insert(i);
  }
  // tree.printTreeLevelOrder();
  // tree.printRoute(10);
  tree.printRoute(50);
  tree.printRoute(500);
  return 0;
}
