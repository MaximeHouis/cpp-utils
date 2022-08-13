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
class ScopedProfiler final
{
public:
    explicit ScopedProfiler(const char* name) noexcept;
    ~ScopedProfiler();

    ScopedProfiler(ScopedProfiler&&) = delete;
    ScopedProfiler(const ScopedProfiler&) = delete;
    ScopedProfiler& operator=(ScopedProfiler&&) = delete;
    ScopedProfiler& operator=(const ScopedProfiler&) = delete;

private:
    const TimePoint m_start;
    const char* const m_name;
};
}  // namespace utils

#if UTILS_WITH_SCOPED_PROFILER
    #define UTILS_SCOPED_PROFILER(x) const utils::ScopedProfiler UTILS_STRCAT(_SCOPED_PROFILER_, __COUNTER__)(x)
#else
    #define UTILS_SCOPED_PROFILER(x) (void) 0
#endif
