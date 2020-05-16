/*
        Title: gate_matrices.h
        Author: Blake Gerard
        Date: 05/16/2020
        Description: Declaration of Eigen-compatible vector to store
        matrix representations of the basic quantum gates enumerated 
        in "gate_enum.h".
*/

#ifndef GATE_MATRICES_H
#define GATE_MATRICES_H

#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <vector>

extern std::vector<Eigen::MatrixXcd, Eigen::aligned_allocator<Eigen::MatrixXcd>> gate_matrices;

#endif