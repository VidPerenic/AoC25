#include <fstream>
#include <sstream>
#include <iostream>

int main() {

  int poz = 50;
  int rot;
  char direction;
  int counter1 = 0;
  int counter2 = 0;

  std::ifstream file("input.txt");
  std::string line{};



  while(std::getline(file, line)){
    std::stringstream ss (line);
    ss >> direction >> rot;

    //rotacija
    if (direction == 'R'){
      poz += rot;
    counter2 += poz/100;} // če gremo u desno normalno prištejemo


    else {
      
      counter2 += (100 - poz + rot) / 100; // (100 - poz +rot) preslikava v prištevanje da ni treba it v minus 

      if(poz==0) counter2--; //če je poz 0 in naslednja v minus še enkrat prišteje tko da treba tako
      
      poz -=rot;
    }

    poz = (100 + poz % 100) % 100;//mapiranje na range 0 do 100

    if(poz==0){counter1++;}
  }
  
  std::cout<< "Rezultat prve naloge:  " << counter1<<std::endl << "Rezultat druge naloge:  "<< counter2;
  

  return 0;
}
