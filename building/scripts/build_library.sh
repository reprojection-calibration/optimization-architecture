#!/bin/bash

set -eoux pipefail

rm --recursive --force /buildroot/build; mkdir /buildroot/build; cd /buildroot/build

cmake -G Ninja /temporary/code
cmake .