#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <unordered_map>

long long dfs(const std::string& node,
              const std::unordered_map<std::string, std::vector<std::string>>& graph,
              std::unordered_map<std::string, long long>& memo);


#endif // FUNCTIONS_H