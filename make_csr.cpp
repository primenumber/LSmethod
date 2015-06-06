#include "make_csr.hpp"

namespace math {

SpMat make_csr() {
  SpMat res;
  // initialize matrix
  int n;
  scanf("%d", &n);
  res.col_size = 0;
  res.row_size = 0;
  for (int i = 0; i < n; ++i) {
    int row, col;
    math::Real val;
    scanf("%d %d %lf", &row, &col, &val);
    res.col_size = std::max(res.col_size, col + 1);
    if (row+1 == res.row_size) {
      if (col == res.cols.back()) {
        res.elems.back() += val;
      } else {
        res.cols.push_back(col);
        res.elems.push_back(val);
      }
    } else {
      res.row_offsets.push_back(res.cols.size());
      res.row_size = std::max(res.row_size, row+1);
      res.cols.push_back(col);
      res.elems.push_back(val);
    }
  }
  res.row_offsets.push_back(res.cols.size());
  return res;
}

} // namespace math
