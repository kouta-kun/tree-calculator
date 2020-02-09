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
