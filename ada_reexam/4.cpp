#include <print>
#include <string>

// Using hashmap or counting array
void minSortering(int arr[100]) {
  int count_arr[201] = {};
  for (size_t i = 0; i < 100; i++) {
    count_arr[arr[i]]++;
  }
  // 0 -> 200 is always constant O(1)
  for (size_t i = 0; i < 201; i++) {
    // O(N)
    for (size_t j = 0; j < count_arr[i]; j++) {
      std::print("{} ", i);
    }
  }
  std::println("");
}

int main(int argc, char *argv[]) {
  int arr[100] = {
      34,  67, 23,  89, 12,  145, 78, 56,  190, 101, 43,  87, 65, 32, 176,
      98,  54, 123, 67, 182, 29,  75, 134, 56,  89,  102, 47, 68, 91, 150,
      33,  77, 24,  88, 13,  146, 79, 200, 191, 102, 44,  88, 66, 33, 177,
      99,  55, 124, 68, 183, 30,  76, 135, 57,  90,  103, 48, 69, 92, 151,
      35,  68, 25,  90, 14,  147, 80, 58,  192, 103, 45,  89, 67, 34, 178,
      100, 56, 125, 69, 184, 31,  77, 136, 58,  91,  104, 49, 70, 93, 152,
      36,  69, 26,  91, 15,  148, 81, 59,  193, 200};
  minSortering(arr);

  return 0;
}
