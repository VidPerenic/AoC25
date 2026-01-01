#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <map>

int main() {

  std::ifstream file("input.txt");
  std::string line;
  
  if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }

  std::map<int, long long> beams; // (lokacija beama; število možnosti za prit v ta beam)
  
  std::getline(file, line);

  beams[line.find('S')] = 1; //prva 

  std::getline(file, line); //druga vrstica je prazna

  int counter1{};

  while( std::getline(file, line)){

    for(size_t i{}; i< line.size(); i++){

      if (line[i] == '^' && beams.find(i) != beams.end()) { //če splitamo beam

        beams[i-1] += beams[i]; //žarek se razpolovi (levo, desno doda sebe, sam se izbriše)
        beams[i+1] += beams[i];
        beams.erase(i);
        counter1++; //prištejemo če  ga zadne žarek (prva naloga)
      }
    }
    std::getline(file, line); //ta vrstica so same pike
  }

  long long counter2{};

  for(auto& p:beams) counter2+=p.second;

  std::cout<<"Prva naloga: "<<counter1<<std::endl<<"Druga naloga: "<<counter2;
    
  return 0;

}
