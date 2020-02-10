//
// Created by kouta on 9/2/20.
//

#include <Constant.hpp>
#include "SubOp.h"

double tree::SubOp::evaluate() {
    if (!was_transformed) {
        this->b = std::make_shared<tree::Constant>(-b->evaluate());
        this->was_transformed = true;
    }
    return AddOp::evaluate();
}

int tree::SubOp::make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) {
    if(!was_transformed) {
        int a_node = this->a->make_graph(nodes, edges);
        int b_node = this->b->make_graph(nodes, edges);
        // shut up clang I know damn well what i'm doing
        auto this_node = Expression::make_graph(nodes, edges);
        nodes[this_node] = "-";
        edges.emplace_back(this_node, a_node);
        edges.emplace_back(this_node, b_node);
        return this_node;
    } else return AddOp::make_graph(nodes, edges);
}

tree::SubOp::~SubOp() = default;
