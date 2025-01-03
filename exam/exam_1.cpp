#include <print>
#include <string>
// Index start at last char in the word string.
int countLettersInWord(std::string word, char letter, int index) {
  if (index < 0) {
    return 0;
  }
  if (word[index] == letter) {
    return 1 + countLettersInWord(word, letter, index - 1);
  } else {
    return countLettersInWord(word, letter, index - 1);
  }
}
int main() {
  std::string word = "banana";
  std::println("banana: {}", countLettersInWord(word, 'a', word.length() - 1));
  return 0;
}
