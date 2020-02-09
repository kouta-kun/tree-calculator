//
// Created by kouta on 9/2/20.
//

#ifndef TREE_CALCULATOR_ADDOP_H
#define TREE_CALCULATOR_ADDOP_H
#include <Expression.hpp>
#include <memory>

namespace tree {
    class AddOp : public Expression<double> {

        std::shared_ptr<Expression<double>> a;
    protected:
        std::shared_ptr<Expression<double>> b;
    public:
        AddOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b);
        double evaluate() override;
    };
};


#endif //TREE_CALCULATOR_ADDOP_H
