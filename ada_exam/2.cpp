#include <print>

int sumDeleligMedTreOgOtte(int N) {
  // Basecase
  if (N < 3)
    return 0;
  int otteMod = N % 8;
  int treMod = N % 3;
  int nextOtteMod = (N - 1) % 8;
  int nextTreMod = (N - 1) % 3;
  int next = nextOtteMod > nextTreMod ? nextTreMod + 1 : nextOtteMod + 1;

  if (otteMod == 0 || treMod == 0) {
    return N + sumDeleligMedTreOgOtte(N - next);
  } else {
    return sumDeleligMedTreOgOtte(N - next);
  }
}

int main(int argc, char *argv[]) {
  std::println("N=20: {}", sumDeleligMedTreOgOtte(20));
  std::println("N=26: {}", sumDeleligMedTreOgOtte(26));
  std::println("N=8: {}", sumDeleligMedTreOgOtte(8));
  return 0;
}
