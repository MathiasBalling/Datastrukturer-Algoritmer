#include "BinaryHeap.h"
#include <iostream>

using namespace std;

int main() {
  try {
    // Create a BinaryHeap instance
    BinaryHeap<int> heap;

    // Insert elements into the heap
    cout << "Inserting elements: 10, 20, 5, 15, 30" << endl;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(15);
    heap.insert(30);

    // Find the minimum element
    cout << "Minimum element in the heap: " << heap.findMin() << endl;

    // Remove the minimum element
    cout << "Removing the minimum element..." << endl;
    heap.deleteMin();
    cout << "New minimum element: " << heap.findMin() << endl;

    // Insert another element
    cout << "Inserting element: 3" << endl;
    heap.insert(3);
    cout << "New minimum element: " << heap.findMin() << endl;

    // Remove all elements
    cout << "Removing all elements from the heap:" << endl;
    while (!heap.isEmpty()) {
      int minItem;
      heap.deleteMin(minItem);
      cout << "Removed: " << minItem << endl;
    }

    // Try finding the minimum in an empty heap
    cout << "Attempting to find minimum in an empty heap..." << endl;
    cout << "Minimum element: " << heap.findMin() << endl;

  } catch (const UnderflowException &) {
    cerr << "UnderflowException: Heap is empty!" << endl;
  } catch (const exception &e) {
    cerr << "Exception: " << e.what() << endl;
  }

  return 0;
}
