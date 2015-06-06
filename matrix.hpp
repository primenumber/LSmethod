#pragma once
#include "level0.hpp"
#include "level1.hpp"

namespace math {

struct SpMat {
  std::vector<int> cols;
  Vector elems;
  std::vector<int> row_offsets;
  int col_size;
  int row_size;
};

} // namespace math
