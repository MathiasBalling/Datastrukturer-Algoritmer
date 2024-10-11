/*
  Skriv en rekursiv algoritme med folgende signatur:
  bool additive(Strings)
  Parameteren indeholder en streng bestäende af cifre, fx. "82842605".
  Algoritmen returnerer true, his parameteren indeholder en substring af tre pả
  hinanden efterfolgende tal, hvor det tredje ciffer er lig med summen af de to
  forrige. I ovenstäende eksempel returneres true, fordi indeks 5 (6) er summen
  af indeks 3 og 4 (4 plus 2). Tip: ASCII-værdien af karakteren '7' er 55.
*/
#include <cassert>
#include <print>
#include <string>

bool additive(std::string str) {
  if (str.size() < 3)
    return false;
  if ((str[2] - '0') == (str[0] - '0') + (str[1] - '0'))
    return true;
  return additive(str.substr(1));
}

int main() {
  assert(additive("82842605") == true);
  assert(additive("82842905") == false);
  assert(additive("12342905") == true);

  std::println("All test passed 😀");
  return 0;
}
