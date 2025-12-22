#include "functions.h"

long long two_sequence_counter(std::string start, std::string end){

    if(start.size() == end.size() &&  start.size()%2 != 0) return 0;// vrne 0 če sta
    long id;
    long long start_ll;
    long long end_ll;


    if(start.size() == 1) id = 0;
    else id = std::stoul(start.substr(0, start.size()/2)); //prva polovica starta

    start_ll = std::stoll(start);
    end_ll = std::stoll(end);

    int i{};
    long long id2{};
    long long count{};

    while(true){
      id2 = std::stoull(std::to_string(id+i)+std::to_string(id+i));
      i++;
      if(id2<start_ll) continue; //preskočimo tiste ki so manjši od start
      if(id2<=end_ll){
      count+=id2;
      } else break; //id2 > end_ll; konec
    } 

    return count;
}

long long multi_sequence_counter(std::string start, std::string end){

    if(start.size() != end.size()) {throw std::invalid_argument("Input string lenghts must be the same");}

    long long start_int = std::stoll(start);
    long long end_int = std::stoll(end);
    std::unordered_set <long long> un_repeated;
    long long count=0;

    for(int i = start.size()/2; i > 0; i--){ //i je število števk ki se ponavljajo
      if(start.size()%i != 0) continue; //preskočimo napačne dolžine
      long id = std::stoul(start.substr(0, i));

      int j{}; //while loop counter
      long long id2{};
      
      while(true){

        std::string id_str = std::to_string(id+j);
        std::string id2_str = id_str;
        for(int k{1}; k < start.size()/i; k++) id2_str = id2_str.append(id_str); // izdelava zaporedja
          
        id2 = std::stoull(id2_str); //zaporedje v številko
        
        j++;
        
        if(id2<start_int) continue;
        if(id2<=end_int){
        un_repeated.insert(id2);
        } else break;
      }
    }
    for (auto x : un_repeated) count+=x;
    
  return count;
}

