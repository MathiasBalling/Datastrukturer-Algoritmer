/*6561 er et eksempel pả et naturligt tal, som kan skrives som X' hvor X og Y er
heltal, dvs. 94. Et andet eksempel er 3125 (55). Skriv en algoritme, som kan
afgore om et givent naturligt tal Z < 100,000 (algoritmens parameter) kan
skrives som Z=XY hvor X og Y er heltal, hvorom det galder, at X > 2 0g Y > 2.

Algoritmens returvardi skal designes säledes, at folgende information kan
udledes fra den:
• Værdien af X (i tilfældet 6561 er X=9).
• Værdien af Y (i tilfældet 6561 er Y=4).
• For det givne Z kan der være flere losningspar (X,Y). For 3125 er der kun et
løsningspar; men for 6561 er X=3 og Y=8 ogsà en mulighed. Hvis der er mere end
én losning, skal den med den storste X-værdi returneres.
• Hvis det givne Z ikke har noget lesningspar (X,Y) eller Z

indeholder en ulovlig værdi, returneres en dummy eller default værdi.
Algoritmen skal optimeres under antagelsen af, at maksimumværdien for Z og
minimumsværdierne for X og Y aldrig andrer sig.
*/
#include <cassert>
#include <cmath>
#include <print>

struct potens_pair {
  int X = 1; // Default value
  int Y = 1; // Default value
};

potens_pair find_potens(int Z) {
  if (Z > 100000)
    return potens_pair();
  potens_pair s;
  // Start at x > 2 -> x = 3
  for (int x = 3; pow(x, 3) < 100000; x++) {
    for (int y = 3; pow(x, y) < 100000; y++) {
      if (pow(x, y) == Z && x > s.X) {
        s.X = x;
        s.Y = y;
      }
    }
  }
  return s;
}

int main() {
  potens_pair s = find_potens(6561);
  std::println("{},{}", s.X, s.Y);

  return 0;
}
