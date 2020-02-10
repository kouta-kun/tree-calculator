//
// Created by kouta on 9/2/20.
//

#include <AddOp.h>
#include <Constant.hpp>
#include <StringUtils.h>
#include <Parser.h>
#include <MulOp.h>
#include <SubOp.h>
#include <DivOp.h>
#include <map>
#include <functional>

template<typename T>
static std::shared_ptr<tree::Expression<double>> subparse(const std::string &input, size_t position) {
    std::shared_ptr<tree::Expression<double>> a = tree::parse(input.substr(0, position));
    std::shared_ptr<tree::Expression<double>> b = tree::parse(input.substr(position + 1));
    return std::make_shared<T>(a, b);
}

static bool checkOpEnclosed(const std::string &input, size_t position) {
    ssize_t balance = 0;
    for (size_t i = position; i < input.size(); i++) {
        switch (input[i]) {
            case '(':
                balance++;
                break;
            case ')':
                balance--;
                break;
        }
        if (balance < 0) return true;
    }
    return false;
}

static std::string::size_type find_unenclosed_op(const std::string &input, const std::string& opList) {
    for(char opToFind : opList) {
        std::string::size_type opPos = input.find(opToFind);
        while (checkOpEnclosed(input, opPos) && opPos != std::string::npos) {
            opPos = input.find(opToFind, opPos + 1);
        }
        if(opPos != std::string::npos) return opPos;
    }
    return std::string::npos;
}

typedef std::function<std::shared_ptr<tree::Expression<double>>(const std::string &, size_t)> ParseFunction;

auto &getParseMap() {
    static const std::map<char, ParseFunction> map = {
            {'+', subparse<tree::AddOp>},
            {'-', subparse<tree::SubOp>},
            {'*', subparse<tree::MulOp>},
            {'/', subparse<tree::DivOp>}
    };
    return map;
}

static bool string_is_parenthesis_expression(const std::string &input) { // must be math_trimmed before calling
    if(input[0] != '(' || input[input.size() - 1] != ')') return false;
    int balance = 1;
    for(int i = 1; i < input.size() - 1; i++) {
        switch(input[i]) {
            case '(': balance++; break;
            case ')': balance--; break;
        }
        if(balance == 0) return false;
    }
    return true;
}

std::shared_ptr<tree::Expression<double>> tree::parse(std::string input) {
    input = math_trim(input);
    if (string_is_parenthesis_expression(input)) {
        input = math_trim(input.substr(1, input.size() - 2));
    }
    std::string::size_type opPos = find_unenclosed_op(input, "+-*/");
    if(opPos != std::string::npos) {
        const ParseFunction &parseFunction = getParseMap().at(input[opPos]);
        return parseFunction(input, opPos);
    }
    return std::make_shared<tree::Constant>(std::stod(math_trim(input)));
}
