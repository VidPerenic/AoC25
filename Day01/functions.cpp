#include "functions.h"

bool isDigit(char c) {
  if (c - '0' >= 0 && c - '0' <= 9) {
    return true;
  }
  return false;
}

int getNumber(string str) {
  int first{-1};
  int second{-1};
  for (char c : str) {
    if (isDigit(c)) {
      if (first == -1) {
        first = c - '0';
      } else {
        second = c - '0';
      }
    }
  }
  if (second == -1) {
    second = first;
  }
  return 10 * first + second;
}

int getNumberStr(string str) {
  vector<string> numbers{"one", "two",   "three", "four", "five",
                         "six", "seven", "eight", "nine"};
  int first{-1};
  int second{-1};
  for (size_t i{0}; i < str.size(); i++) {
    char c = str[i];
    if (isDigit(c)) {
      if (first == -1) {
        first = c - '0';
      } else {
        second = c - '0';
      }
    } else {
      for (size_t j{0}; j < numbers.size(); j++) {
        if (str.substr(i, numbers[j].size()) == numbers[j]) {
          if (first == -1) {
            first = j + 1;
          } else {
            second = j + 1;
          }
        }
      }
    }
  }
  if (second == -1) {
    second = first;
  }
  return 10 * first + second;
}
