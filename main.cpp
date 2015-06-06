#include <cstdlib>
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
  boost::timer t;
  math::Vector res = math::CGLSMethod(spm, vec);
  math::Vector diff = spm * res - vec;
  std::cerr << "time: " << t.elapsed() << std::endl;
  for (math::Real val : res) {
    std::printf("%f\n", val);
  }
  std::cerr << "error: " << math::abs(diff) << std::endl;
  return 0;
}
