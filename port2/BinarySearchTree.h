#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <algorithm>
#include <iostream>
using namespace std;

class BinaryNode {
public:
  int element;
  BinaryNode *left;
  BinaryNode *right;

  BinaryNode(const int &theElement, BinaryNode *lt, BinaryNode *rt)
      : element{theElement}, left{lt}, right{rt} {}

  BinaryNode(int &&theElement, BinaryNode *lt, BinaryNode *rt)
      : element{std::move(theElement)}, left{lt}, right{rt} {}
};

class BinarySearchTree {
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree &rhs);
  BinarySearchTree(BinarySearchTree &&rhs);
  ~BinarySearchTree();

  const int &findMin() const;
  const int &findMax() const;
  bool contains(const int &x) const;
  bool isEmpty() const;

  void makeEmpty();
  void insert(const int &x);
  void insert(int &&x);
  void remove(const int &x);

  // Print methods
  void printTreeInOrder() const;    // In order
  void printTreePreOrder() const;   // Pre order
  void printTreePostOrder() const;  // Post order
  void printTreeLevelOrder() const; // Level order

  // Counts
  void printCountNodes() const;
  void printCountLeaves() const;
  void printCountFullNodes() const;

  void printInternalPathLenght() const;

  void printCountBranches() const;

private:
  BinaryNode *root;

  void insert(const int &x, BinaryNode *&t);
  void insert(int &&x, BinaryNode *&t);
  void remove(const int &x, BinaryNode *&t);
  BinaryNode *findMin(BinaryNode *t) const;
  BinaryNode *findMax(BinaryNode *t) const;

  BinaryNode *getOnlyChild(BinaryNode *t) const;

  bool contains(const int &x, BinaryNode *t) const;

  void makeEmpty(BinaryNode *&t);
  BinaryNode *clone(BinaryNode *t) const;

  // Print methods
  void printTreeInOrder(BinaryNode *t) const;    // In order
  void printTreePreOrder(BinaryNode *t) const;   // Pre order
  void printTreePostOrder(BinaryNode *t) const;  // Post order
  void printTreeLevelOrder(BinaryNode *t) const; // Level order

  // Counts
  int countNodes(BinaryNode *t) const;
  int countLeaves(BinaryNode *t) const;
  int countFullNodes(BinaryNode *t) const;
  int internalPathLenght(BinaryNode *t, int depth) const;
  int countBranches(BinaryNode *t) const;
};

#endif
