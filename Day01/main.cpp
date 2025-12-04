#include "functions.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>

int main() {

  std::ifstream file("input.txt");
  std::string line{};

  std::string rot_s{};
  int rot = 50;
  int rot_c = 50; //prejšnja rotacija
  char direction;
  int counter = 0;
  int counter2 = 0;
  int linec{0};

  while(std::getline(file, line)){
    std::stringstream ss (line);
    ss >> direction >> rot_s;
   /* 
    //rotacija
    if (direction == 'R'){
      rot += std::stoi(rot_s);
    }
    else {rot -= std::stoi(rot_s);}
 */
     //1 naloga
     
    //if(rot%100 == 0) counter++;
 
    //2 naloga
   


    //rotacija
    if (direction == 'R'){
      rot += std::stoi(rot_s);
      counter += rot/100;
      }

    else {
      rot -= std::stoi(rot_s);
      if(rot<=0 && rot>-100 && rot != -std::stoi(rot_s))counter++; //na nič pridemo samo s premikanjem v levo
      else counter -= rot/100 -1;

    }

    

    rot = (100 + rot % 100) % 100;//mapiranje na range 0 do 100

    linec++;
  }

  std::cout<< "Rezultat prve naloge" << counter2;

  return 0;
}
//prava 6892