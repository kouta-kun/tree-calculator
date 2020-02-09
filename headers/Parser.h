//
// Created by kouta on 9/2/20.
//

#ifndef TREE_CALCULATOR_PARSER_H
#define TREE_CALCULATOR_PARSER_H

#include <Expression.hpp>
#include <string>

namespace tree {
    std::shared_ptr<Expression<double>> parse(std::string input);
}


#endif //TREE_CALCULATOR_PARSER_H
