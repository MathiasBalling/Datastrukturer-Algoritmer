/*
  Skriv en rekursiv algoritme, som har et naturligt tal som parameter og
  returnerer summen af de ulige tals kvadrater fra 1 til N.

  Eksempel: kaldt med parameteren 8 returneres 84 (1^2 + 3^2 + 5^2 + 7^2).

  Det er vigtigt at optimere algoritmen, sä overflodige rekursive kald undgas.
*/
#include <cassert>
#include <print>

int un_even_square(int n) {
  if (n == 1)
    return 1;
  else if (n % 2 == 0)
    return un_even_square(n - 1);
  else if (n % 2 != 0)
    return n * n + un_even_square(n - 2);

  return 0;
}

int main() {
  assert(un_even_square(1) == 1);
  assert(un_even_square(3) == 10);
  assert(un_even_square(4) == 10);
  assert(un_even_square(10) == 165);

  std::println("All test passed 😀");
  return 0;
}
