#include "BinarySearchTree.h"
#include <deque>

BinarySearchTree::BinarySearchTree() : root{nullptr} {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
    : root{nullptr} {
  root = clone(rhs.root);
}

BinarySearchTree::BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root} {
  rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree() { makeEmpty(); }

const int &BinarySearchTree::findMin() const {
  if (isEmpty())
    return -1;
  return findMin(root)->element;
}

const int &BinarySearchTree::findMax() const {
  if (isEmpty())
    return -1;
  return findMax(root)->element;
}

bool BinarySearchTree::contains(const int &x) const {
  return contains(x, root);
}

bool BinarySearchTree::isEmpty() const { return root == nullptr; }

void BinarySearchTree::printTreeInOrder() const {
  if (isEmpty())
    cout << "Empty tree" << endl;
  else
    printTreeInOrder(root);
}
void BinarySearchTree::printTreePreOrder() const {
  if (isEmpty())
    cout << "Empty tree" << endl;
  else
    printTreePreOrder(root);
}
void BinarySearchTree::printTreePostOrder() const {
  if (isEmpty())
    cout << "Empty tree" << endl;
  else
    printTreePostOrder(root);
}

void BinarySearchTree::printTreeLevelOrder() const {
  if (isEmpty())
    cout << "Empty tree" << endl;
  else
    printTreeLevelOrder(root);
}

void BinarySearchTree::printCountNodes() const {
  cout << countNodes(root) << endl;
}
void BinarySearchTree::printCountLeaves() const {
  cout << countLeaves(root) << endl;
}
void BinarySearchTree::printCountFullNodes() const {
  cout << countFullNodes(root) << endl;
}

void BinarySearchTree::printInternalPathLenght() const {
  cout << internalPathLenght(root, 0) << endl;
}

void BinarySearchTree::makeEmpty() { makeEmpty(root); }

void BinarySearchTree::insert(const int &x) { insert(x, root); }

void BinarySearchTree::insert(int &&x) { insert(std::move(x), root); }

void BinarySearchTree::remove(const int &x) { remove(x, root); }

void BinarySearchTree::insert(const int &x, BinaryNode *&t) {
  if (t == nullptr)
    t = new BinaryNode{x, nullptr, nullptr};
  else if (x < t->element)
    insert(x, t->left);
  else if (t->element < x)
    insert(x, t->right);
  else
    ; // Duplicate; do nothing
}

void BinarySearchTree::insert(int &&x, BinaryNode *&t) {
  if (t == nullptr)
    t = new BinaryNode{std::move(x), nullptr, nullptr};
  else if (x < t->element)
    insert(std::move(x), t->left);
  else if (t->element < x)
    insert(std::move(x), t->right);
  else
    ; // Duplicate; do nothing
}

void BinarySearchTree::remove(const int &x, BinaryNode *&t) {
  if (t == nullptr)
    return; // Item not found; do nothing
  if (x < t->element)
    remove(x, t->left);
  else if (t->element < x)
    remove(x, t->right);
  else if (t->left != nullptr && t->right != nullptr) // Two children
  {
    t->element = findMin(t->right)->element;
    remove(t->element, t->right);
  } else {
    BinaryNode *oldNode = t;
    t = (t->left != nullptr) ? t->left : t->right;
    delete oldNode;
  }
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *t) const {
  if (t == nullptr)
    return nullptr;
  if (t->left == nullptr)
    return t;
  return findMin(t->left);
}

BinaryNode *BinarySearchTree::findMax(BinaryNode *t) const {
  if (t != nullptr)
    while (t->right != nullptr)
      t = t->right;
  return t;
}

bool BinarySearchTree::contains(const int &x, BinaryNode *t) const {
  if (t == nullptr)
    return false;
  else if (x < t->element)
    return contains(x, t->left);
  else if (t->element < x)
    return contains(x, t->right);
  else
    return true; // Match
}

void BinarySearchTree::makeEmpty(BinaryNode *&t) {
  if (t != nullptr) {
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
  }
  t = nullptr;
}

void BinarySearchTree::printTreeInOrder(BinaryNode *t) const {
  if (t != nullptr) {
    printTreeInOrder(t->left);
    cout << t->element << endl;
    printTreeInOrder(t->right);
  }
}

void BinarySearchTree::printTreePreOrder(BinaryNode *t) const {
  if (t != nullptr) {
    cout << t->element << endl;
    printTreePreOrder(t->left);
    printTreePreOrder(t->right);
  }
}

void BinarySearchTree::printTreePostOrder(BinaryNode *t) const {
  if (t != nullptr) {
    printTreePostOrder(t->left);
    printTreePostOrder(t->right);
    cout << t->element << endl;
  }
}

void BinarySearchTree::printTreeLevelOrder(BinaryNode *t) const {
  std::deque<BinaryNode *> level_queue = {t};
  while (!level_queue.empty()) {
    auto node = level_queue.front();
    cout << node->element << endl;

    if (node->left != nullptr) {
      level_queue.push_back(node->left);
    }
    if (node->right != nullptr) {
      level_queue.push_back(node->right);
    }

    level_queue.pop_front();
  }
}

BinaryNode *BinarySearchTree::clone(BinaryNode *t) const {
  if (t == nullptr)
    return nullptr;
  else
    return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}

int BinarySearchTree::countNodes(BinaryNode *t) const {
  if (t == nullptr)
    return 0;
  return 1 + countNodes(t->left) + countNodes(t->right);
}

int BinarySearchTree::countLeaves(BinaryNode *t) const {
  if (t == nullptr)
    return 0;
  if (t->left == nullptr && t->right == nullptr)
    return 1;
  return countLeaves(t->left) + countLeaves(t->right);
}

int BinarySearchTree::countFullNodes(BinaryNode *t) const {
  if (t == nullptr)
    return 0;
  if (t->left != nullptr && t->right != nullptr)
    return 1 + countFullNodes(t->left) + countFullNodes(t->right);
  else
    return countFullNodes(t->left) + countFullNodes(t->right);
}

int BinarySearchTree::internalPathLenght(BinaryNode *t, int depth) const {
  if (t == nullptr)
    return 0;
  return depth + internalPathLenght(t->left, depth + 1) +
         internalPathLenght(t->right, depth + 1);
}

void BinarySearchTree::printCountBranches() const {
  int count = countBranches(root);
  cout << "Branches count: " << count << endl;
}

BinaryNode *BinarySearchTree::getOnlyChild(BinaryNode *t) const {
  if (t->left != nullptr && t->right == nullptr)
    return t->left;
  else if (t->right != nullptr && t->left == nullptr) {
    return t->right;
  } else {
    return nullptr;
  }
}

int BinarySearchTree::countBranches(BinaryNode *t) const {
  // Node X har ét barn.
  // Node X har ingen søskende.
  // Node X’s barn har ingen søskende.
  // Node X’s barn har ét barn, som er et blad.

  // Early return
  if (t == nullptr)
    return 0;

  // Check for only child (X)
  BinaryNode *X = getOnlyChild(t);
  if (X == nullptr) {
    // Not only child
    // Can be 0 or 2 children

    // Skip nodes with siblings
    if (t->left != nullptr && t->right != nullptr) {
      return countBranches(t->left) + countBranches(t->right);
    }

    // Skip nodes with no children
    return 0;
  }

  // Check for child with only child (X's child)
  BinaryNode *X_Child = getOnlyChild(X);
  if (X_Child == nullptr) {
    // Not only child
    // Can be 0 or 2 children

    // Skip nodes with siblings
    if (X->left != nullptr && X->right != nullptr) {
      return countBranches(X->left) + countBranches(X->right);
    }

    // Skip nodes with no children
    return 0;
  }

  // Check for child with only child (X's child child)
  BinaryNode *X_Child_Child = getOnlyChild(X_Child);
  if (X_Child_Child == nullptr) {
    // Not only child
    // Can be 0 or 2 children

    // Skip nodes with siblings
    if (X_Child->left != nullptr && X_Child->right != nullptr) {
      return countBranches(X_Child->left) + countBranches(X_Child->right);
    }

    // Skip nodes with no children
    return 0;
  }

  // Check for leaf (X's child's child and leaf)
  if (X_Child_Child->left == nullptr && X_Child_Child->right == nullptr) {
    cout << "Branch at: " << X->element << endl;
    return 1;
  }

  cout << "Not leaf at: " << X_Child_Child->element << endl;

  // Not leaf check from onlychild and down
  return countBranches(X_Child);
}
