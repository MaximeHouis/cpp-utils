/*
 * Copyright (c) 2021-2021 [fill name later]
 *
 * This software is provided "as-is", without any express or implied warranty. In no event
 *     will the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose, including commercial
 *     applications, and to alter it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim that you
 *     wrote the original software. If you use this software in a product, an acknowledgment
 *     in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be misrepresented
 * as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#pragma once

#include <version>

/**
 * Ensure 2 levels of macro expansion to stringify preprocessor macros
 */
#define _UTILS_STR2(x)       #x
#define _UTILS_STR1(x)       _UTILS_STR2(x)
#define _UTILS_STRCAT2(x, y) x##y
#define _UTILS_STRCAT1(x, y) _UTILS_STRCAT2(x, y)

/**
 * Stringify preprocessor
 */
#define UTILS_STR(x)         _UTILS_STR1(x)

/**
 * Concatenates x and y
 */
#define UTILS_STRCAT(x, y)   _UTILS_STRCAT1(x, y)

/**
 * Check if std::execution is supported, still need to include <execution> in files using the feature.
 * Added a comma at the end so that we can use `std::for_each(UTILS_EXEC_PAR_UNSEQ vec.begin(), ...)`
 * regardless std::execution is supported or not.
 */
#if defined(__cpp_lib_execution) && defined(__cpp_lib_parallel_algorithm)
    #define UTILS_HAS_EXECUTION_POLICIES 1
    #define UTILS_EXEC_SEQ               std::execution::seq,        // C++17
    #define UTILS_EXEC_PAR               std::execution::par,        // C++17
    #define UTILS_EXEC_PAR_UNSEQ         std::execution::par_unseq,  // C++17
    #define UTILS_EXEC_UNSEQ             std::execution::unseq,      // C++20
#else
    #define UTILS_HAS_EXECUTION_POLICIES 0
    #define UTILS_EXEC_SEQ
    #define UTILS_EXEC_PAR
    #define UTILS_EXEC_PAR_UNSEQ
    #define UTILS_EXEC_UNSEQ
#endif

namespace utils::features {
static constexpr bool execution_policies = UTILS_HAS_EXECUTION_POLICIES;
}
