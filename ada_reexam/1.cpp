#include <print>

bool sumAfToTalLigParameterV1(int arr[], int len, int X) {
  // O(n^2)
  for (int i = 0; i < len - 1; i++) {
    for (int j = 1; j < len; j++) {
      int sum = arr[i] + arr[j];
      if (sum == X) {
        return true;
      }
    }
  }
  return false;
}
bool sumAfToTalLigParameterV2(int arr[], int len, int X) {
  // O(n)
  int right_idx = len - 1;
  int left_idx = 0;
  while (true) {
    int sum = arr[left_idx] + arr[right_idx];
    if (sum == X) {
      std::println("{} {} {}", left_idx, right_idx, sum);
      return true;
    } else if (sum > X) {
      right_idx--;
    } else if (sum < X) {
      left_idx++;
    }
    if (left_idx == right_idx) {
      std::println("{} {} {}", left_idx, right_idx, sum);
      return false;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  int array[6] = {5, 6, 7, 8, 9, 10};
  std::println("{}", sumAfToTalLigParameterV1(array, 6, 18)); // True
  std::println("{}", sumAfToTalLigParameterV2(array, 6, 18)); // True
  int array2[12] = {5, 6, 7, 8, 9, 10, 11, 15, 18, 19, 22, 31};
  std::println("{}", sumAfToTalLigParameterV2(array2, 12, 53)); // True
  int array3[12] = {5, 6, 7, 8, 9, 10, 11, 15, 18, 19, 22, 31};
  std::println("{}", sumAfToTalLigParameterV2(array2, 12, 44)); // False

  return 0;
}
