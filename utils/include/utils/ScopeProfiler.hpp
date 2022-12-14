/*
 * Copyright (c) 2022-2022 [fill name later]
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

#include <utils/Macros.hpp>
#include <utils/Time.hpp>

#include <chrono>
#include <utility>

namespace utils {
/**
 * Profile code inside a scope.
 * Intended to be used with the `UTILS_WITH_SCOPE_PROFILER` macro.
 */
class ScopeProfiler final
{
public:
    explicit ScopeProfiler(const char* name) noexcept;
    ~ScopeProfiler();

    ScopeProfiler(ScopeProfiler&&) = delete;
    ScopeProfiler(const ScopeProfiler&) = delete;
    ScopeProfiler& operator=(ScopeProfiler&&) = delete;
    ScopeProfiler& operator=(const ScopeProfiler&) = delete;

private:
    const TimePoint m_start;
    const char* const m_name;
};
}  // namespace utils

#if UTILS_WITH_SCOPE_PROFILER
    #define UTILS_SCOPE_PROFILER(x) \
        [[maybe_unused]] const utils::ScopeProfiler UTILS_STRCAT(_SCOPE_PROFILER_, __COUNTER__)(x)
#else
    #define UTILS_SCOPE_PROFILER(x) (void) 0
#endif
