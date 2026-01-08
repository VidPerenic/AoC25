#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "functions.h"

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string from, to;

        ss >> from;
        from.pop_back(); // odstranimo ':'

        while (ss >> to) {
            graph[from].push_back(to);
        }
    }

    std::unordered_map<std::string, long long> memo;
    long long count = dfs("you", graph, memo);

    std::cout << "Prva naloga: " << count << std::endl;

    return 0;
}
