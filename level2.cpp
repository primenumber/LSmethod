#include "level2.hpp"

#include "mkl.h"

namespace std {

using namespace math;

Vector operator*(const SpMat &lhs, const Vector &rhs) {
  Vector res(lhs.row_size);
  char n = 'N';
  mkl_cspblas_dcsrgemv(&n, &lhs.row_size, lhs.elems.data(), lhs.row_offsets.data(),
      lhs.cols.data(), rhs.data(), res.data());
  return res;
}

Vector trans_mv(const SpMat &lhs, const Vector &rhs) {
  Vector res(lhs.row_size);
  char n = 'T';
  mkl_cspblas_dcsrgemv(&n, &lhs.row_size, lhs.elems.data(), lhs.row_offsets.data(),
      lhs.cols.data(), rhs.data(), res.data());
  return res;
}

} // namespace std
