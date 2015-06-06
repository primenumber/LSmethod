#pragma once
#include <tuple>
#include <vector>

#include "sparse_matrix.hpp"
#include "matrix.hpp"
#include "level0.hpp"
#include "level1.hpp"

namespace std {

using namespace math;

Vector operator*(const SpMat &lhs, const Vector &rhs);
// y = A^T * x
Vector trans_mv(const SpMat &lhs, const Vector &rhs);

} // namespace math
