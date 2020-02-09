//
// Created by kouta on 9/2/20.
//

#include <Constant.hpp>
#include "SubOp.h"

double tree::SubOp::evaluate() {
    if (!was_transformed) {
        this->b = std::make_shared<tree::Constant>(-b->evaluate());
        this->was_transformed = true;
    }
    return AddOp::evaluate();
}
