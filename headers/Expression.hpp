#ifndef TREE_EXPRESSION_HPP
#define TREE_EXPRESSION_HPP

#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

namespace tree {
    template<typename T>
    class Expression {
    public:
        virtual T evaluate() = 0;
        virtual ~Expression();
        virtual int make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges);
        std::string serialize_graph();
    };
}

template<typename T>
tree::Expression<T>::~Expression() = default;

template<typename T>
int tree::Expression<T>::make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) {
    std::set<int> keys;
    std::transform(nodes.begin(), nodes.end(),
                   std::inserter(keys, keys.end()),
                   [](auto pair) { return pair.first; });
    int this_node = 0;
    if(!keys.empty()) this_node = *(--keys.end()) + 1;
    return this_node;
}

template<typename T>
std::string tree::Expression<T>::serialize_graph() {
    std::map<int, std::string> nodes;
    std::map<int, int> hierarchy;
    std::vector<std::pair<int,int>> edges;
    this->make_graph(nodes, edges);
    std::stringstream output;
    for(const auto &pair : edges) {
        output << pair.first;
        output << ':';
        output << pair.second;
        output << ';';
    }
    int level = 0;
    std::string operations = "+-*/";
    for(auto it = nodes.rbegin(); it != nodes.rend(); it++) {
        hierarchy[it->first] = level;
        if(operations.find_first_of(it->second) != std::string::npos) {
            level++;
        }
    }
    for(const auto &node : nodes) {
        output << '\n';
        output << node.second;
        output << '!';
        output << hierarchy[node.first];
    }
    return output.str();
}
#endif