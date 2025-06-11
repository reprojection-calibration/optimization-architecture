#include <gtest/gtest.h>

#include "optimization_architecture/cost_functions.hpp"

using namespace reprojection_calibration::optimization_architecture;

TEST(TestCostFunctions, OneParameterCostFunction) {
  OneParameterCostFunction const cost_function;

  double const parameter{10.0};
  double residual;
  cost_function.operator()<double>(&parameter, &residual);

  EXPECT_NEAR(residual, 0.0, 1e-6);
}

TEST(TestCostFunctions, TwoParameterCostFunction) {
  TwoParameterCostFunction const cost_function;

  std::array<double, 2> const parameters{6.0, 4.0};
  double residual;
  cost_function.operator()<double>(parameters.data(), &residual);

  EXPECT_NEAR(residual, 0.0, 1e-6);
}