#!/bin/bash

set -eoux pipefail

# TODO: We should use this script/stage in CI, so we do not need the different github actions

find /temporary/code -iname '*.cpp' -o -iname '*.hpp' | xargs clang-format --dry-run --Werror

cppcheck /temporary/code --enable=all --error-exitcode=1 -I /temporary/code/include --suppress=missingIncludeSystem