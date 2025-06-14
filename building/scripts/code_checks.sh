#!/bin/bash

set -eoux pipefail

find /temporary/building -iname '*.sh' -print0 | xargs --null shellcheck

find /temporary/code \( -iname '*.cpp' -o -iname '*.hpp' \) -print0 | xargs --null clang-format --dry-run --Werror
cppcheck /temporary/code --enable=all --error-exitcode=1 -I /temporary/code/include --suppress=missingIncludeSystem