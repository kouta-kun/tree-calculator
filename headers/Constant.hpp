//
// Created by kouta on 9/2/20.
//

#ifndef TREE_CALCULATOR_CONSTANT_HPP
#define TREE_CALCULATOR_CONSTANT_HPP

#include "Expression.hpp"

namespace tree {
    class Constant : public tree::Expression<double> {
        double value;
    public:
        double evaluate() override;
        explicit Constant(double v);
        ~Constant() override;
        int make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) override;
    };
}

#endif //TREE_CALCULATOR_CONSTANT_HPP
