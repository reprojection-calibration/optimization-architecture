#pragma once

#include <array>
#include <ceres/ceres.h>
#include <functional>

namespace reprojection_calibration::optimization_architecture {

class CameraParameters {
public:
  virtual double *GetParameterPtr() = 0;
};

class OneParameterCamera : public CameraParameters {
public:
  explicit OneParameterCamera(double const parameter)
      : one_parameter_{parameter} {}

  double *GetParameterPtr() override { return &one_parameter_; }

private:
  double one_parameter_;
};

class TwoParameterCamera : public CameraParameters {
public:
  explicit TwoParameterCamera(std::array<double, 2> const &parameters)
      : two_parameter_{parameters} {}

  double *GetParameterPtr() override { return two_parameter_.data(); }

private:
  std::array<double, 2> two_parameter_;
};

void OptimizerHandler(
    double const data, CameraParameters *const camera_parameters,
    std::function<ceres::CostFunction *(double)> cost_function_factory) {

  ceres::Problem problem;
  ceres::CostFunction *cost_function{cost_function_factory(data)};
  problem.AddResidualBlock(cost_function, nullptr,
                           camera_parameters->GetParameterPtr());

  ceres::Solver::Options const options;
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);
}

} // namespace reprojection_calibration::optimization_architecture