cmake_minimum_required(VERSION 3.15)
project(tree_calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
add_executable(tree_calculator main.cpp Constant.cpp headers/Constant.hpp AddOp.cpp headers/AddOp.h Parser.cpp headers/Parser.h StringUtils.cpp headers/StringUtils.h headers/Expression.hpp MulOp.cpp headers/MulOp.h SubOp.cpp headers/SubOp.h DivOp.cpp headers/DivOp.h)