#include <gtest/gtest.h>

#include "optimization_architecture/optimizer_handler.hpp"

using namespace reprojection_calibration::optimization_architecture;

TEST(TestOptimizerHanlder, ParameterOverrides) {
  OneParameterCamera one_parameter{10.0};
  EXPECT_NEAR(*one_parameter.GetParameterPtr(), 10.0, 1e-12);

  TwoParameterCamera two_parameter{{6.0, 4.0}};
  EXPECT_NEAR(two_parameter.GetParameterPtr()[0], 6.0, 1e-12);
  EXPECT_NEAR(two_parameter.GetParameterPtr()[1], 4.0, 1e-12);
}
