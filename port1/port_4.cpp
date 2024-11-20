/*
 Skriv en algoritme, der har et array af usorterede, entydige naturlige tal som
 input og find de tre tal i arrayet, his sum er tattest pa en potens af 2. Det
 samme tal kan mà bruges én gang. Algoritmens returværdi skal vare et
 heltalsarray, som forst indeholder de tre tal og dernast den tilherende potens
 af to (fx 512). Kaldt med arrayet {23,56,22,11,65,89,3,44,87,910,45,35,98},
 returneres de tre tal 89, 3, 35 og potensen af 2: 128. Hvad er Store-O
 tidskompleksiteten af din algoritme? Begrund dit svar og diskuter mulighederne
 for at optimere din losning yderligere.
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <print>

std::vector<int> find_sum_of_power_of_two(std::vector<int> input) {
  std::vector<int> result;
  int smallest_diff = std::numeric_limits<int>::max();

  for (size_t i = 0; i < input.size() - 2; i++) {
    for (size_t j = i + 1; j < input.size() - 1; j++) {
      for (size_t k = j + 1; k < input.size(); k++) {
        int sum = input[i] + input[j] + input[k];
        double log_sum = std::log2(sum);
        int nearest_power_of_two =
            static_cast<int>(std::pow(2, std::round(log_sum)));
        int dist_from_log = abs(sum - nearest_power_of_two);

        if (dist_from_log == 0) {
          return {input[i], input[j], input[k], nearest_power_of_two};
        }

        if (dist_from_log < smallest_diff) {
          smallest_diff = dist_from_log;
          result = {input[i], input[j], input[k], nearest_power_of_two};
        }
      }
    }
  }

  return result;
}

std::vector<int> find_sum_of_power_of_two_v2(std::vector<int> input) {
  // Alternative implementation using two-pointer
  std::vector<int> result;
  int smallest_diff = std::numeric_limits<int>::max();

  std::sort(input.begin(), input.end());

  for (size_t i = 0; i < input.size() - 2; i++) {
    size_t left = i + 1;
    size_t right = input.size() - 1;

    while (left < right) {
      int sum = input[i] + input[left] + input[right];
      double log_sum = std::log2(sum);
      int nearest_power_of_two =
          static_cast<int>(std::pow(2, std::round(log_sum)));
      int dist_from_log = abs(sum - nearest_power_of_two);

      if (dist_from_log == 0) {
        return {input[i], input[left], input[right], nearest_power_of_two};
      }

      if (dist_from_log < smallest_diff) {
        smallest_diff = dist_from_log;
        result = {input[i], input[left], input[right], nearest_power_of_two};
      }

      if (sum < nearest_power_of_two) {
        left++;
      } else {
        right--;
      }
    }
  }

  return result;
}

std::vector<int> findClosestToPowerOfTwo(const std::vector<int> &arr) {
  int n = arr.size();
  int closestSum = std::numeric_limits<int>::max();
  int closestPowerOfTwo = 1;
  std::vector<int> result(
      4, 0); // to store the 3 numbers and the closest power of 2

  // Sort array to use two-pointer technique
  std::vector<int> sortedArr = arr;
  std::sort(sortedArr.begin(), sortedArr.end());

  // Fix one element and use two-sum approach for the other two
  for (int i = 0; i < n - 2; ++i) {
    int targetSum = sortedArr[i];

    int left = i + 1;
    int right = n - 1;

    while (left < right) {
      int sum = targetSum + sortedArr[left] + sortedArr[right];

      // Find the closest power of 2 for the current sum
      int powerOfTwo = 1;
      while (powerOfTwo < sum) {
        powerOfTwo *= 2;
      }

      // Check if we found a closer sum to a power of 2
      if (std::abs(sum - powerOfTwo) <
          std::abs(closestSum - closestPowerOfTwo)) {
        closestSum = sum;
        closestPowerOfTwo = powerOfTwo;
        result = {sortedArr[i], sortedArr[left], sortedArr[right],
                  closestPowerOfTwo};
      }

      // Also check the lower power of 2
      int lowerPowerOfTwo = powerOfTwo / 2;
      if (std::abs(sum - lowerPowerOfTwo) <
          std::abs(closestSum - closestPowerOfTwo)) {
        closestSum = sum;
        closestPowerOfTwo = lowerPowerOfTwo;
        result = {sortedArr[i], sortedArr[left], sortedArr[right],
                  closestPowerOfTwo};
      }

      // Adjust pointers based on how close the current sum is to the powers of
      // 2
      if (sum < powerOfTwo) {
        ++left; // Need a larger sum
      } else {
        --right; // Need a smaller sum
      }
    }
  }

  return result;
}

int main() {

  std::vector t1 = {23, 56, 22, 11, 65, 89, 3, 44, 87, 910, 45, 35, 98};
  std::vector res_t1 = {89, 3, 35, 128};
  std::vector res = find_sum_of_power_of_two(t1);
  std::println("{}", res);
  assert(res == res_t1);
  std::vector res_v2 = findClosestToPowerOfTwo(t1);
  std::println("{}", res_v2);

  std::println("All test passed!");
  return 0;
}
