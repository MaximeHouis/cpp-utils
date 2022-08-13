#!/usr/bin/env sh

find utils app -name "*.cpp" -or -name "*.hpp" | xargs clang-format -i --verbose
