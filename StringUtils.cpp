//
// Created by kouta on 9/2/20.
//

#include "StringUtils.h"

std::string math_trim(const std::string &input) {
    auto start = input.find_first_not_of(" \t\n");
    auto end = input.find_last_of("0123456789.()") + 1;
    return input.substr(start, end-start);
}
