#pragma once

#include "matrix.hpp"
#include "level0.hpp"
#include "level1.hpp"
#include "level2.hpp"

namespace math {

Vector CGLSMethod(const SpMat &mat, const Vector &vec);

} // namespace math
