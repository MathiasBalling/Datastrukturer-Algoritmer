/*
Skriv en rekursiv metode med folgende signatur:
int logTo (int N)
Algoritmen returner totals-logaritmen af N, og det er en forudsatning, at N er
et naturligt tal og en potens af 2. Kaldt med N = 32 returneres 5, 0g med N =
4096 returneres 12.
 */
#include <cassert>
#include <print>

int logTo(int N) {
  if (N < 2)
    return 0;
  return 1 + logTo(N / 2);
}

int main() {
  assert(logTo(4096) == 12);
  assert(logTo(50) == 5);
  assert(logTo(32) == 5);
  assert(logTo(3) == 1);
  assert(logTo(2) == 1);
  assert(logTo(1) == 0);

  std::println("All test passed!");
  return 0;
}
