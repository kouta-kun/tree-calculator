//
// Created by kouta on 9/2/20.
//

#ifndef TREE_CALCULATOR_MULOP_H
#define TREE_CALCULATOR_MULOP_H
#include <Expression.hpp>
#include <memory>

namespace tree {
    class MulOp : public Expression<double> {

        std::shared_ptr<Expression<double>> a, b;
    public:
        MulOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b);
        double evaluate() override;
        ~MulOp() override;
        int make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) override;
    };
}


#endif //TREE_CALCULATOR_MULOP_H
