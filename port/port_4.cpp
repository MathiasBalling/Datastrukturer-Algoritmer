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

int main() {

  std::vector t1 = {23, 56, 22, 11, 65, 89, 3, 44, 87, 910, 45, 35, 98};
  std::vector res_t1 = {89, 3, 35, 128};
  std::vector res = find_sum_of_power_of_two(t1);
  std::println("{}", res);
  assert(res == res_t1);

  std::println("All test passed!");
  return 0;
}
