#include <iostream>
#include <memory>
#include <Parser.h>

int main() {
    std::cout << "write your expression: ";
    std::string a;
    std::getline(std::cin, a);
    std::shared_ptr<tree::Expression<double>> expr = tree::parse(a);
    std::cout << a << " = " << expr->evaluate();
    return 0;
}
