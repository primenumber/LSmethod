#include "solver.hpp"

#include <cmath>

#include <iostream>
#include <thread>
#include <future>

namespace math {

Real eps = 1.0;

Vector CGLSMethod(const SpMat &mat, const Vector &vec) {
  Vector r = trans_mv(mat, vec);
  Vector x(r.size());
  Vector p, d, t;
  std::future<Real> sqn_r_f = std::async(std::launch::async, sqnorm, std::ref(r));
  d = vec;
  p = r;
  t = mat * p;
  Real sqn_r = sqn_r_f.get();
  for (int i = 0; ; ++i) {
    if ((i % 10) == 0) std::cerr << i;
    Real alpha = sqn_r / sqnorm(t);
    fma(x, alpha, p);
    fma(d, -alpha, t);
    Vector old_r = r;
    r = trans_mv(mat, d);
    Real diff = abs(r);
    if (diff < eps) break;
    if ((i % 10) == 0) std::cerr << ' ' << diff << '\r';
    Real old_sqn_r = sqn_r;
    sqn_r = sqnorm(r);
    Real beta = sqn_r / old_sqn_r;
    p = r + beta * p;
    t = mat * p;
  }
  std::cerr << '\n';
  return x;
}

} // namespace math
