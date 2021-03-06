//
// Created by kouta on 9/2/20.
//

#ifndef TREE_CALCULATOR_DIVOP_H
#define TREE_CALCULATOR_DIVOP_H

#include <Expression.hpp>
#include <memory>

namespace tree {
    class DivOp : public Expression<double> {
        std::shared_ptr<Expression<double>> a, b;
    public:
        DivOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b);

        double evaluate() override;
        ~DivOp() override;
        int make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) override;
    };
}


#endif //TREE_CALCULATOR_DIVOP_H
