#!/usr/bin/env sh

find lib app -name "*.cpp" -or -name "*.hpp" | xargs clang-format -i --verbose
