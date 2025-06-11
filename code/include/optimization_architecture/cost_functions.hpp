#pragma once

#include <ceres/ceres.h>

namespace reprojection_calibration::optimization_architecture {

struct OneParameterCostFunction {
  OneParameterCostFunction(double const data) : data_{data} {}

  template <typename T>
  bool operator()(const T *const x, T *const residual) const {
    residual[0] = 10.0 - x[0];

    return true;
  }

  static ceres::CostFunction *Create(double const data) {
    return new ceres::AutoDiffCostFunction<OneParameterCostFunction, 1, 1, 1>(
        data);
  }

private:
  double data_;
};

struct TwoParameterCostFunction {
  template <typename T>
  bool operator()(const T *const x, T *const residual) const {
    residual[0] = 10.0 - x[0] - x[1];

    return true;
  }
};

} // namespace reprojection_calibration::optimization_architecture