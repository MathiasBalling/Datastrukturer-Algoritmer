#include <print>
long bigOh(double N) {
  long x = 0;
  long y = 0;
  for (int i = 0; i < N; i++) // for-loop nummer 1
  {
    for (int j = 0; j < pow(log(N), 2); j++)
    // log er ln (den naturlige logaritme)
    {
      for (int k = 0; k <= sqrt(N); k++) {
        x++;
      }
    }
    i += i;
  }

  for (long k = 0; k < N * sqrt(N); k++) // for-loop nummer 2
    y++;

  std::println("N:{},x:{},y:{}", N, x, y);
  return x + y;
}
int main() {
  // for (int i = 300; i < 350; i++) {
  //   bigOh(i);
  // }
  bigOh(320);
  bigOh(1000000);

  return 0;
}
