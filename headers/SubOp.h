//
// Created by kouta on 9/2/20.
//

#ifndef TREE_CALCULATOR_SUBOP_H
#define TREE_CALCULATOR_SUBOP_H


#include <AddOp.h>

namespace tree {
    class SubOp : public tree::AddOp {
    private:
        bool was_transformed = false;
    public:
        SubOp(const std::shared_ptr<Expression<double>> &a, const std::shared_ptr<Expression<double>> &b) :
                AddOp(a, b) {}

        double evaluate() override;

        ~SubOp() override;
        int make_graph(std::map<int, std::string> &nodes, std::vector<std::pair<int, int>> &edges) override;
    };
};


#endif //TREE_CALCULATOR_SUBOP_H
