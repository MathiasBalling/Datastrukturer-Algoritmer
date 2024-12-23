#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Record {
  int id;
  std::string name;
  int value;
};

int main() {
  std::ifstream file("data.txt");
  if (!file.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }

  std::vector<Record> records;
  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string token;
    Record record;

    // Parse each line
    if (std::getline(ss, token, ';')) {
      record.id = std::stoi(token);
    }
    if (std::getline(ss, token, ';')) {
      record.name = token;
    }
    if (std::getline(ss, token, ';')) {
      record.value = std::stoi(token);
    }

    records.push_back(record);
  }

  file.close();

  // Output parsed data
  for (const auto &rec : records) {
    std::cout << "ID: " << rec.id << ", Name: " << rec.name
              << ", Value: " << rec.value << std::endl;
  }

  return 0;
}
