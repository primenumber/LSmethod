#include <cstdlib>
#include <cmath>
#include <iostream>
#include <random>

#include "mkl.h"

#include <boost/timer.hpp>

#include "level0.hpp"
#include "level1.hpp"
#include "solver.hpp"
#include "make_csr.hpp"
#include "matrix.hpp"

int main(int argc, char **argv) {
  auto spm = math::make_csr();
  int m;
  std::cin >> m;
  math::Vector vec(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> vec[i];
  }
  std::cerr << "start" << std::endl;
  std::cerr << spm.row_size << ',' << spm.col_size << ',' << spm.elems.size() << std::endl;
  boost::timer t;
  math::Vector res = math::CGLSMethod(spm, vec);
  math::Vector diff = spm * res - vec;
  std::cerr << "time: " << t.elapsed() << std::endl;
  for (math::Real val : res) {
    std::printf("%f\n", val);
  }
  double error = math::abs(diff);
  std::cerr << "error: " << error << std::endl;
  std::cerr << "standard deviation: " << (error/std::sqrt(spm.row_size)) << std::endl;
  std::cerr << "average absolute prediction error: " << math::average(diff) << std::endl;
  return 0;
}
