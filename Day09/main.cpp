#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

struct Point2d{
  long long x ,y;
};

int main() {

  std::ifstream file("input.txt");
  std::string line;

   if (!file.is_open()) {
      std::cerr << "Could not open file.\n";
      return 1;
    }

  std::vector<Point2d> points;
  char comma;

  std::stringstream ss(line);
  Point2d p;

   
  while(std::getline(file, line)){
    std::stringstream ss(line);
    ss>>p.x>>comma>>p.y;
    points.push_back(p);
  }
 
  long long maxArea{};

  for (size_t i{}; i < points.size(); i++) {
    for (size_t j = i + 1; j < points.size(); j++) {
      long long dx = std::abs(points[i].x - points[j].x+1); //vključuje oba roba
      long long dy = std::abs(points[i].y - points[j].y+1);
      long long area = dx * dy;

      if (area > maxArea) {
          maxArea = area;
      }
     }
    }

    std::cout<<"Prva naloga: "<<maxArea;
  return 0;
}
