//
// Created by kouta on 9/2/20.
//

#include "Constant.hpp"

tree::Constant::Constant(double v) {
    this->value = v;
}

double tree::Constant::evaluate() {
    return this->value;
}
