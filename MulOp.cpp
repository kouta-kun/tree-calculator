//
// Created by kouta on 9/2/20.
//

#include "MulOp.h"

tree::MulOp::MulOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b) {
    this->a = a;
    this->b = b;
}

double tree::MulOp::evaluate() {
    return a->evaluate() * b->evaluate();
}
