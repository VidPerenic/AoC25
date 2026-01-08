#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "functions.h"

int main() {

  std::ifstream file("input.txt");
  std::string line;
  
  if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }

  std::vector<Point3d> points;
  char comma;

  std::stringstream ss(line);
  Point3d p;

   
  while(std::getline(file, line)){
    std::stringstream ss(line);
    ss>>p.x>>comma>>p.y>>comma>>p.z;
    points.push_back(p);
  }

  std::multimap<long long, std::pair<size_t,size_t>> distances; //če slučajno mata dve škatli isto razdaljo

  for(int i{}; i<points.size(); i++){
    for(int j = i+1; j<points.size(); j++){
      distances.insert({points[i].dist_sqr(points[j]), {i,j}}); // v map zapisujemo razdalje med točkami in njihove indekse
    }
  }

  std::vector<std::set<size_t>> circuts;
 
  int count{1};
  bool exists = false;
  size_t prev_exist;

  for(auto& d: distances){
    
    count++;
    exists = 0;

    for(int i{}; i< circuts.size(); i++){

      if (circuts[i].count(d.second.first)) {//count preveri če je noter; d=map, second = value (pair); first, second = junction boxes

        if(exists){
          circuts[prev_exist].insert(circuts[i].begin(), circuts[i].end()); //Če najdemo da obstaja prej združimo tega k tistemu ki je obstajalo prej 
          circuts[i].clear();   //pobrišemo set, nesmemo ga odstraniti iz vektorja ker dolžina nebo več enaka
          continue;
        }    
        circuts[i].insert(d.second.second);
        exists = true;
        prev_exist = i;
        
      } 
      else if (circuts[i].count(d.second.second)) {

        if(exists){
          circuts[prev_exist].insert(circuts[i].begin(), circuts[i].end()); 
          circuts[i].clear(); 
          continue;
        } 
        circuts[i].insert(d.second.first);
        exists = true;
        prev_exist = i;
      }
    }
    //ko preverimo vse in ni bilo najdenega dodamo novega
    if(!exists) circuts.push_back({d.second.first,d.second.second});

    if (count==999){
      std::sort(circuts.begin(), circuts.end(), [](const auto& a, const auto& b) {return a.size() > b.size();});
      std::cout<<"Prva naloga: "<<circuts[0].size()*circuts[1].size()*circuts[2].size()<<std::endl;

    }
    else if ((*std::max_element(circuts.begin(), circuts.end(), [](auto& a, auto& b) {return a.size() < b.size();})).size()==1000){ 
      //če ima največji circut 1000 elemtov smo dodali vse 
    std::cout<<"Druga naloga: "<<points[d.second.first].x*points[d.second.second].x<<std::endl;
    break;
    }
  }

  return 0;

}
