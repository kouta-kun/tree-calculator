//
// Created by kouta on 9/2/20.
//

#ifndef TREE_CALCULATOR_ADDOP_H
#define TREE_CALCULATOR_ADDOP_H
#include <Expression.hpp>
#include <memory>

namespace tree {
    class AddOp : public Expression<double> {

    protected:
        std::shared_ptr<Expression<double>> b;
        std::shared_ptr<Expression<double>> a;
    public:
        AddOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b);
        double evaluate() override;
        ~AddOp() override;
        int make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) override;
    };
};


#endif //TREE_CALCULATOR_ADDOP_H
