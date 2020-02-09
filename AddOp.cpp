//
// Created by kouta on 9/2/20.
//

#include "AddOp.h"

tree::AddOp::AddOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b) {
    this->a = a;
    this->b = b;
}

double tree::AddOp::evaluate() {
    return a->evaluate() + b->evaluate();
}