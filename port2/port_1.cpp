/*
 */
#include <cctype>
#include <cstddef>
#include <print>
#include <string>
#include <unordered_map>

std::string highest_word_count(std::string input) {
  if (input.empty()) {
    return "";
  }
  std::unordered_map<std::string, int> word_count;
  while (!input.empty()) {
    size_t dilimiter_index = input.find(' ');
    std::string word = "";
    if (dilimiter_index != std::string::npos) {
      word = input.substr(0, dilimiter_index);
      // Make word lowercase
      for (auto &c : word) {
        c = std::tolower(c);
      }
      input = input.substr(dilimiter_index + 1);
    } else {
      // Last word here
      word = input;
      // Make word lowercase
      for (auto &c : word) {
        c = std::tolower(c);
      }
      input.erase();
    }
    if (word.find(',') != std::string::npos ||
        word.find('.') != std::string::npos) {
      // Dilimiter will always be in the end.
      word.erase(word.end() - 1);
    }
    if (word_count.contains(word)) {
      word_count[word]++;
    } else {
      word_count[word] = 1;
    }
  }

  std::pair<std::string, int> highest_word_count = {"", 0};
  for (const auto &word_pair : word_count) {
    if (word_pair.second > highest_word_count.second) {
      highest_word_count.first = word_pair.first;
      highest_word_count.second = word_pair.second;
    }
  }

  return highest_word_count.first;
}

int main() {
  std::string word =
      highest_word_count("HELLO MY FRIEND. I Know you. I do do do");

  std::println("{}", word);

  std::println("All test passed!");
  return 0;
}
