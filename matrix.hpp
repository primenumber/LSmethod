#pragma once
#include "level0.hpp"
#include "level1.hpp"
#include "mkl.h"

namespace math {

struct SpMat {
  std::vector<MKL_INT> cols;
  Vector elems;
  std::vector<MKL_INT> row_offsets;
  int col_size;
  int row_size;
};

} // namespace math
