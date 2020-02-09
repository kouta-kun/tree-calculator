#ifndef TREE_EXPRESSION_HPP
#define TREE_EXPRESSION_HPP

namespace tree {
    template<typename T>
    class Expression {
    public:
        virtual T evaluate() = 0;
    };
}
#endif