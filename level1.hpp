#pragma once
#include <cassert>

#include <algorithm>
#include <vector>

#include "level0.hpp"

namespace math {

using Vector = std::vector<Real>;

// y += a * x;
Vector fma(Vector &y, const Real &a, const Vector &x);

Real sqnorm(const Vector &vec);

Real abs(const Vector &vec);

Real average(const Vector &vec);

Real max(const Vector &vec);

} // namespace math

namespace std {

using namespace math;

Vector operator+(const Vector &lhs, const Vector &rhs);

Vector operator-(const Vector &lhs, const Vector &rhs);

Vector operator*(const Real &lhs, const Vector &rhs);

Real operator*(const Vector &lhs, const Vector &rhs);

} // namespace std
