#pragma once

namespace reprojection_calibration::optimization_architecture {

struct OneParameterCostFunction {
  template <typename T>
  bool operator()(const T *const x, T *const residual) const {
    residual[0] = 10.0 - x[0];

    return true;
  }
};

struct TwoParameterCostFunction {
  template <typename T>
  bool operator()(const T *const x, T *const residual) const {
    residual[0] = 10.0 - x[0] - x[1];

    return true;
  }
};

} // namespace reprojection_calibration::optimization_architecture