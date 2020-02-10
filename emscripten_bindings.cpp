//
// Created by kouta on 10/2/20.
//

#include <Parser.h>
#include <Expression.hpp>
#include <emscripten/bind.h>
#include <memory>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(tree_calc) {
    class_<tree::Expression<double>>("Expression")
        .function("evaluate", &tree::Expression<double>::evaluate)
        .function("serialize_graph", &tree::Expression<double>::serialize_graph)
        .smart_ptr<std::shared_ptr<tree::Expression<double>>>("Expression");
    function("parseExpr", &tree::parse);
}