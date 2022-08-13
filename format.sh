#!/usr/bin/env sh

find utils tests -name "*.cpp" -or -name "*.hpp" | xargs clang-format -i --verbose
