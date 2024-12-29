#include <functional>
#include <print>
#include <string>

const std::string vowels = "aeiouy";
int antalVokaler(std::string str, int l) {
  // Basecase
  if (l < 0) {
    return 0;
  }
  if (vowels.find(str[0]) != std::string::npos) {
    return 1 + antalVokaler(str.substr(1), l - 1);
  } else {
    return antalVokaler(str.substr(1), l - 1);
  }
}

int main(int argc, char *argv[]) {
  std::string test = "nangnagnjdhdeeee";
  std::println("{}", test.substr(1));
  std::println("{}", antalVokaler(test, test.length() - 1));
  return 0;
}
