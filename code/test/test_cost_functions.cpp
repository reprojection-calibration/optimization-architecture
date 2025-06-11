#include <gtest/gtest.h>

#include "optimization_architecture/cost_functions.hpp"

using namespace reprojection_calibration::optimization_architecture;

TEST(TestCostFunctions, DeleteDoesNothing) {
  EXPECT_NO_THROW(DeleteXxx());
  EXPECT_NE(0, 0);
}
