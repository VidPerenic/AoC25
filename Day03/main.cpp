#include <fstream>
#include <string>
#include <iostream>

int main() {

  std::ifstream file("input.txt");
  std::string line{};

  if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }
  
  int counter = 0;

  long long counter2 = 0;

  
  while(std::getline(file, line)){
    std::string number_str;

    auto max = std::max_element(line.begin(), line.end()-1);

    number_str += *max; //druga števka

    max = std::max_element(max+1, line.end());

    number_str += *max; //druga števka

    counter += std::stoi(number_str);
    
    //druga naloga
    std::string number2_str;

    max = line.begin()-1;

    for(int i{11}; i>=0; i--){ 
      max = std::max_element(max+1, line.end()-i);
      number2_str += *max;
    }
    counter2+= std::stoll(number2_str);

  }
  std::cout<<"Prva naloga: "<< counter<< "   Druga naloga: "<< counter2<<std::endl;

  return 0;
}

 