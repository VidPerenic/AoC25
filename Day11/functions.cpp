#include "functions.h"

long long dfs(const std::string& node,
              const std::unordered_map<std::string, std::vector<std::string>>& graph,
              std::unordered_map<std::string, long long>& memo)
{
    if (node == "out")
        return 1;

    // ali smo že poračunali
    if (memo.count(node))
        return memo[node]; //vrnemo izračunanega

    long long paths = 0;

    for (const auto& next_node : graph.at(node)) {
        paths += dfs(next_node, graph, memo);}
    

    memo[node] = paths; //izračun shranimo
    return paths;
}