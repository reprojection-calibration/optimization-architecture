#!/bin/bash

set -eoux pipefail

# TODO: We should use this script/stage in CI, so we do not need the different github actions

find /temporary/code -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format --dry-run --Werror

cppcheck /temporary/code -I /temporary/code/include -i cmake-build-* --error-exitcode=1 --enable=all --suppress=missingIncludeSystem