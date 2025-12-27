#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


int main() {

  std::ifstream file("input.txt");
  std::string line;

   if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }

  std::vector <std::string> lines_str;
  std::vector <std::vector<int>> lines(4); //
 
  std::vector <char> operations; 

  int x{};

  char op{};

  int count{};

  long long counter{};
 
  //branje številk
  while(count<4 && std::getline(file, line)){
    
    lines_str.push_back(line);

    std::stringstream ss(line);
   
    while(ss>> x){ //ločevanje po presledkih
      lines[count].push_back(x);
      }
      count++;
    }

  //branje znakov
  std::getline(file, line);   
  lines_str.push_back(line);
  std::stringstream ss(line);

  while(ss >> op){
    operations.push_back(op);
    }

  long long  multiplication = 1; //zmnožek
  
  //Prva naloga
    for(int i{}; i < lines[0].size(); i++ ){
      if(operations[i] == '+'){
        for(int j{}; j<4; j++ ) {counter+=lines[j][i];}
      }
      else {

       multiplication = 1; //resetiranje zmnoževalnika
      
      for(int k{}; k<4; k++ ){
         multiplication *= lines[k][i];
      }
      counter+= multiplication;
    }
  }
   
 std::cout<<"Prva naloga: " <<counter<<std::endl;;


// naloga 2

counter = 0;
multiplication = 0;
//naredimo nov seznam ki je transponiranka prvemu

std::vector <std::string> transposed_lines_str;

for(size_t i{}; i<lines_str[0].size(); i++){
  line = ""; //recikliramo line
  for(size_t j{}; j<4;j++){
    if(lines_str[j][i] != ' '){
      line+=lines_str[j][i]; // brez presledkov 
    }
  }
  transposed_lines_str.push_back(line); //med posameznimi računi so empty string
}



size_t i{1};

multiplication = 1;

char current_op = operations[0];

for(auto number_str : transposed_lines_str){
  if (number_str.empty()) {
    current_op = operations[i];
    i++;
    if(multiplication != 1) { //multiplication je 1 razen če smo ga spreminjali
      counter+=multiplication;
      multiplication = 1; //resetiranje
    }
    continue;
  }
  if(current_op == '+'){
    counter+=std::stoi(number_str);
  }
  else {
    multiplication*=std::stoi(number_str);
  }
}


std::cout<<"Druga naloga: "<<counter<<std::endl;
  return 0;
}
