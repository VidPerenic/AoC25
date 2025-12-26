#include <fstream>
#include <sstream>
#include <iostream>
#include "functions.h"

int main() {

  std::ifstream file("input.txt");
  std::string line{};

  if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }

  std::string start;
  std::string end;

  unsigned long long counter1 = 0;
  unsigned long long counter2 = 0;

  while(std::getline(file, line, ',')){

    std::stringstream ss(line);
    std::getline(ss, start, '-');   // parsanje
    std::getline(ss, end);
 

    counter1 += two_sequence_counter(start, end);
      
    
    if (start.size()!= end.size()){ //razdelitev na dve območji ki so istih dolžin (npr 45-110-> 45-99; 99-110) zdaj potrebujemo 99

      std::string end2 = {'9'}; //naredimo string '9'
      for(int i{1}; i<start.size(); i++){end2.push_back('9');} // dobimo string samih 9 n krat

      //izračunamo vsak range posebej
      counter2 += multi_sequence_counter(start, end2);
      counter2 += multi_sequence_counter(std::to_string(std::stoll(end2)+1), end);

    }else counter2 += multi_sequence_counter(start, end); // če so iste dolžine številk
    
  }
  std::cout<< "Prva naloga: "<< counter1<< std::endl<<"Druga naloga: "<<counter2<<std::endl;
  return 0;
}

