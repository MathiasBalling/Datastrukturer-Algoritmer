#include <cmath>
#include <print>

int main() {
  std::vector<int> prevals;
  for (int i = 0; i < 20; i++) {
    int val = (3 + (int)std::pow(i, 2)) % 13;
    bool in = false;
    for (auto v : prevals) {
      if (v == val) {
        in = true;
      }
    }
    if (!in)
      std::println("{}", val);
  }
  return 0;
}
