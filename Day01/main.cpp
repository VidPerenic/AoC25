#include "functions.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream file("input.txt");
  string line{};
  int sum{};
  int sum2{};
  while (getline(file, line)) {
    sum += getNumber(line);
    sum2 += getNumberStr(line);
  }
  cout << "Part 1: " << sum << endl;
  cout << "Part 2: " << sum2 << endl;
  return 0;
}
