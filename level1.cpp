#include "level1.hpp"

#include <vector>

#include "mkl.h"

namespace std {

using namespace math;

Real operator*(const Vector &lhs, const Vector &rhs) {
  return cblas_ddot(lhs.size(), lhs.data(), 1, rhs.data(), 1);
}

Vector operator*(const Real &lhs, const Vector &rhs) {
  Vector res(rhs.size());
  cblas_daxpy(rhs.size(), lhs, rhs.data(), 1, res.data(), 1);
  return res;
}

Vector operator*=(Vector &lhs, const Real &rhs) {
  cblas_dscal(lhs.size(), rhs, lhs.data(), 1);
  return lhs;
}

Vector operator+=(Vector &lhs, const Vector &rhs) {
  cblas_daxpy(lhs.size(), 1, rhs.data(), 1, lhs.data(), 1);
  return lhs;
}

Vector operator+(const Vector &lhs, const Vector &rhs) {
  Vector res(lhs);
  return res += rhs;
}

Vector operator-=(Vector &lhs, const Vector &rhs) {
  cblas_daxpy(lhs.size(), -1, rhs.data(), 1, lhs.data(), 1);
  return lhs;
}

Vector operator-(const Vector &lhs, const Vector &rhs) {
  Vector res(lhs);
  return res -= rhs;
}

} // namespace std

namespace math {

Vector fma(Vector &y, const Real &a, const Vector &x) {
  cblas_daxpy(y.size(), a, x.data(), 1, y.data(), 1);
  return y;
}

Real sqnorm(const Vector &vec) {
  return vec * vec;
}

Real abs(const Vector &vec) {
  return cblas_dnrm2(vec.size(), vec.data(), 1);
}

Real average(const Vector &vec) {
  return cblas_dasum(vec.size(), vec.data(), 1) / vec.size();
}

Real max(const Vector &vec) {
  return vec[cblas_idamax(vec.size(), vec.data(), 1)];
}

} // namespace math
