//
// Created by kouta on 9/2/20.
//

#include "DivOp.h"


tree::DivOp::DivOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b) {
    this->a = a;
    this->b = b;
}

double tree::DivOp::evaluate() {
    return a->evaluate() / b->evaluate();
}

int tree::DivOp::make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) {
    int a_node = this->a->make_graph(nodes, edges);
    int b_node = this->b->make_graph(nodes, edges);
    auto this_node = Expression::make_graph(nodes, edges);
    nodes[this_node] = "/";
    edges.emplace_back(this_node, a_node);
    edges.emplace_back(this_node, b_node);
    return this_node;
}

tree::DivOp::~DivOp() = default;
