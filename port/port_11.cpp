/*
Tabellen nedenfor reprasenterer de afgivne stemmer ved et valg.
{7,4,3,5,3,1,6,4,5,1,7,5}
I dette eksempel er der 7 kandidater (1-7), og der er afgivet 12 stemmer.
Kandidat 6 fik 1 stemme, kandidaterne 1, 3, 4 og 7 fik hver 2 stemmer, kandidat
5 fik 3 stemmer, and kandidat 2 fik 0 stemmer. Opgaven gảr ud pa at skrive en
algoritme, som kaldt med tabellen og eventuelt tabellens langde, kan afgore om
en kandidat fik mere end 50 % af stemmerne. I sa fald returneres kandidatens
nummer. Hvis ingen kandidat fik over 50% af stemmerne, returneres -1. leksemplet
opnäede ingen af kandidaterne flertal, 0g der returneres - 1. Hvad er din
algoritmes tidskompleksitet?
*/
#include <cassert>
#include <print>
#include <unordered_map>
#include <vector>

int winning_cadidate(std::vector<int> cadidates) {
  std::unordered_map<int, int> cadidate_count = {};
  for (const auto cadidate : cadidates) {
    if (cadidate_count.contains(cadidate)) {
      cadidate_count[cadidate]++;
      if (cadidate_count[cadidate] > cadidates.size() / 2) {
        return cadidate;
      }
    } else {
      cadidate_count[cadidate] = 1;
    }
  }
  return -1;
}

int main() {

  assert(winning_cadidate({7, 4, 3, 5, 3, 1, 6, 4, 5, 1, 7, 5}) == -1);
  assert(winning_cadidate({7, 7, 3, 5, 7, 1, 6, 7, 5, 7, 7, 7}) == 7);
  std::println("All test passed 😀");
  return 0;
}
