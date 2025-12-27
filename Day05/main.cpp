#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {

  std::ifstream file("input.txt");
  std::string line;

   if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }

  std::string first; //string ker ga zapišemo z getline

  long long spoil; 

  std::pair<long long, long long> range;
  std::vector <std::pair<long long, long long>> all_ranges;

 
  
  int counter = 0;

 
  size_t del_loc;//lokacija

  while(std::getline(file, line) && !line.empty()){ // branje do prazne vrstice
    
    std::stringstream ss(line);
    
    std::getline(ss, first , '-');
    range.first = std::stoll(first);

    //ostanek ss gre v drugo vrednost
    ss>>range.second;
  
    all_ranges.push_back(range);
    }


    std::sort(all_ranges.begin(), all_ranges.end()); //sortiramo po startu

    //izdelava območij brez prekrivanja

    std::vector<std::pair<long long, long long>> merged;

    merged.push_back(all_ranges[0]); //Prvo območje prepišemo

    for (const auto& interval : all_ranges) {
        auto& last = merged.back().second; // zadnja v merged

        if (interval.first <= last) { 
            if (!(interval.second <= last))
            last = interval.second; //če se prekriva ampak ne cel, zapišemo novo zadnjo vrednost (prek reference)

        } else {
            // Če se ne prekriva dodamo kot nov interval
            merged.push_back(interval);
        }
    }

    //prva naloga
    while(std::getline(file, line)){ 

      spoil= std::stoll(line);

      for(auto x: merged){

        if(spoil>=x.first && spoil<= x.second){counter++;
        break;}
      }
    }
  
std::cout<< "Prva naloga :  " <<counter;

long long count2{};
 for(auto x: merged){
  count2 += x.second-x.first+1; //območje vključuje oba roba zato +1
 }

 std::cout<< "    Druga naloga :  " <<count2;
  return 0;
}
