#include <cassert>
#include <fmt/core.h>
#include <stack>
#include <string>

bool balPar(std::string text) {
  if (text.empty())
    return true;

  std::stack<char> stack;
  for (const auto &c : text) {
    if (c == '(') {
      stack.push('(');
    } else if (c == ')') {
      if (!stack.empty()) {
        stack.pop();
      } else {
        return false;
      }
    }
  }

  if (stack.empty()) {
    return true;
  } else {
    return false;
  }
}

void exc_1() {
  assert(balPar("") == true);
  assert(balPar("(Test)") == true);
  assert(balPar("((Test)") == false);
  assert(balPar("((Test))") == true);
  assert(balPar("((Test)))") == false);
  assert(balPar("((Test)))))") == false);
  assert(balPar(")(Test)") == false);
}

int main() {
  exc_1();

  fmt::println("All test passed 😀");
  return 0;
}
