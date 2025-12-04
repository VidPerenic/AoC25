#include <fstream>
#include <sstream>
#include <iostream>

int main() {

  std::string rot_s{};
  int poz = 50;
  int rot;
  char direction;
  int counter1 = 0;
  int counter2 = 0;

  std::ifstream file("input.txt");
  std::string line{};

  while(std::getline(file, line)){
    std::stringstream ss (line);
    ss >> direction >> rot_s;

    rot = std::stoi(rot_s);
 
    //rotacija
    if (direction == 'R'){
      poz += rot;} // če gremo u desno normalno prištejemo
    else {
      poz = 100 - poz + rot; // preslikava premikov na pozitivne številke ker u negativnih je ful edge casov p.s. ne me uprašat kako vem
    }

    counter2 += poz/100; // tolikokrat ko delimo s 100 smo šli čez

    poz = (100 + poz % 100) % 100;//mapiranje na range 0 do 100

    if(poz==0)counter1++;
  }

  std::cout<< "Rezultat prve naloge:  " << counter1<<std::endl << "Rezultat druge naloge:  "<< counter2;
  

  return 0;
}
//prava 6892