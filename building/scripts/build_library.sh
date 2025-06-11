#!/bin/bash

set -eoux pipefail

cmake -G Ninja -S /temporary/code -B /buildroot/build
cmake --build /buildroot/build