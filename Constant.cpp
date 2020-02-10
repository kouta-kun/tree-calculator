//
// Created by kouta on 9/2/20.
//

#include <set>
#include <algorithm>
#include "Constant.hpp"

tree::Constant::Constant(double v) {
    this->value = v;
}

double tree::Constant::evaluate() {
    return this->value;
}

int tree::Constant::make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) {
    int this_node = Expression<double>::make_graph(nodes, edges);
    nodes[this_node] = std::to_string(this->value);
    return this_node;
}

tree::Constant::~Constant() = default;
