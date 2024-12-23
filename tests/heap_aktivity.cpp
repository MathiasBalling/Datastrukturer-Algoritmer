#include "Aktivitet.h"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <print>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string kritiskVej("");

// Deserialize data from a file
vector<Aktivitet> createTable() {
  std::ifstream file("data.txt");
  if (!file.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return {};
  }

  std::vector<Aktivitet> aktiviteter;
  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string token;
    int event = -1;
    string task = "";
    int duration = -1;

    // Parse each line
    if (std::getline(ss, token, ';')) {
      event = std::stoi(token);
    }
    if (std::getline(ss, token, ';')) {
      task = token;
    }
    if (std::getline(ss, token, ';')) {
      duration = std::stoi(token);
    }

    Aktivitet aktivitet = Aktivitet(event, task, duration);
    aktiviteter.push_back(aktivitet);
  }

  file.close();
  return aktiviteter;
}

int main() {
  vector<Aktivitet> tabel = createTable();

  int totalDuration = 0;

  for (size_t i = 0; i < tabel.size(); i++)
    totalDuration += tabel[i].getDuration();

  std::println("Antal aktiviteter:     {}", tabel.size());
  std::println("Gennemsnitlig varighed: {}",
               (float)totalDuration / tabel.size());

  int laengdeKritiskVej = 0;
  int aktuelEvent = 1;
  int indeks = 0;
  int maxVarighedAktuelEvent = 0;
  string maxTask = "";
  string minTask = "";      // ny
  string finalMinTask = ""; // ny

  while (true) {
    while (indeks < tabel.size() && tabel[indeks].getEvent() == aktuelEvent) {
      if (maxVarighedAktuelEvent < tabel[indeks].getDuration()) {
        maxVarighedAktuelEvent = tabel[indeks].getDuration();
        maxTask = tabel[indeks].getTask();
      }

      indeks++;
    }

    laengdeKritiskVej += maxVarighedAktuelEvent;
    kritiskVej += maxTask;
    maxVarighedAktuelEvent = 0;
    maxTask = "";

    if (indeks == tabel.size())
      break;
    aktuelEvent = tabel[indeks].getEvent();
  }

  std::println("Lenght of Critical Path: {}", laengdeKritiskVej);
  std::println("Critical Path:           {}", kritiskVej);

  int index = 0;
  int event_nb = 1;
  while (index < tabel.size()) {
    std::vector<Aktivitet> status;
    while (index < tabel.size() && tabel[index].getEvent() == event_nb) {
      status.push_back(tabel[index]);
      index++;
    }

    std::sort(status.begin(), status.end(), [](Aktivitet a, Aktivitet b) {
      return a.getDuration() > b.getDuration();
    });
    for (auto &akt : status) {
      std::print("{}:{} ", akt.getTask(), akt.getDuration());
    }
    std::println("");
    event_nb++;
  }

  return 0;
}
