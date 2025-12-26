#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int main() {

  std::ifstream file("input.txt");
  std::string line{};  

  if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }

  std::vector <std::string> locations;
  
  //zapis v vektor
  std::getline(file, line); 
  locations.push_back(std::string(line.size()+2, '.')); //dodajanje padding
  locations.push_back('.'+ line +'.'); //ker smo jo prebrali da dobimo dolžino moramo tudi shranit

  while(std::getline(file, line)){
    locations.push_back('.'+ line +'.');
  }
  locations.push_back(std::string(line.size()+2, '.'));
  

  int rolls{};

  // adjacent pozicije (indeksne razlike)
  int i_loc[8] = {-1,-1,-1, 0, 0, 1, 1, 1}; //vrstica
  int j_loc[8] = {-1, 0, 1,-1, 1,-1, 0, 1}; //stolpec

  int line_size = locations[0].size();

  for (int i{1}; i<locations.size()-1; i++){
    for(int j{1}; j<line_size-1; j++){
      int counter{};
      if(locations[i][j]=='@'){
        for(int k{}; k<8; k++){
          if(locations[i+i_loc[k]][j+j_loc[k]]=='@') counter++;
        }
        if(counter<4) rolls++;
       }
    }
  }

  //2 naloga

  int rolls2{};
  int rolls2_prev{};

  while(true){
  
  for (int i{1}; i<locations.size()-1; i++){

    for(int j{1}; j<line_size-1; j++){

      int counter{};

      if(locations[i][j]=='@'){

        for(int k{}; k<8; k++){

          if(locations[i+i_loc[k]][j+j_loc[k]]=='@') counter++;
        }
        if(counter<4) {
          
          rolls2++;
          locations[i][j]='.';
        }
       }
    }
  }
  if(rolls2==rolls2_prev) break;
  else rolls2_prev = rolls2;
  }
  std::cout<<"Resitev 1 naloge: "<< rolls<< "    Resitev 2 naloge: "<<rolls2;
  return 0;
}

