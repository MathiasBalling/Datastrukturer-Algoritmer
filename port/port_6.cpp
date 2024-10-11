/*Skriv en rekursiv algoritme med folgende signatur:
int sumDivisibleBy3 (int N)
Algoritmen returnerer summen af heltal sterre end 0 og mindre end eller lig med
N, som er dividérbare med 3. Kaldt med N = 12 er den korrekte returvardi 30
(3+6+9+12). Kaldt med N = 14 er den korrekte returvardi ogs 30. Din algoritme
skal optimeres säledes, at overflodige rekursive kald undgas.
*/

#include <cassert>
#include <print>

int sumDivisibleBy3(int N) {
  if (N == 0)
    return 0;
  else if (N % 3 == 0)
    return N + sumDivisibleBy3(N - 3);
  else {
    return sumDivisibleBy3(N - (N % 3));
  }
}

int main() {

  assert(sumDivisibleBy3(12) == 30);
  assert(sumDivisibleBy3(14) == 30);
  std::println("{}", sumDivisibleBy3(30));

  std::println("All test passed 😀");

  return 0;
}
