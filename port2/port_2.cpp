#include "BinarySearchTree.h"
#include <print>

int main(int argc, char *argv[]) {
  std::vector<int> inputs = {7, 4,  28, 3,  55, 2,  51, 60,
                             1, 48, 58, 69, 40, 57, 35};
  auto tree = BinarySearchTree();
  for (int i : inputs) {
    tree.insert(i);
  }

  // Print the tree to garantee that the tree is correct as per the assignment
  std::println("Level Order");
  tree.printTreeLevelOrder();
  std::println("Counts");
  tree.printCountNodes();
  tree.printCountLeaves();
  tree.printCountFullNodes();
  tree.printInternalPathLenght();

  std::println("Counting branches:");
  tree.printCountBranches();

  return 0;
}
