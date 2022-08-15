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

#include <algorithm>
#include <limits>
#include <utility>

namespace utils {
struct Math
{
    template<typename T>
    [[nodiscard]] static constexpr T lerp(T min, T max, T delta) noexcept
    {
        if (max < min) [[unlikely]]
            std::swap(min, max);
        return (max - min) * delta + min;
    }

    template<typename T>
    [[nodiscard]] static constexpr T lerpClamped(T min, T max, T delta) noexcept
    {
        return std::clamp(lerp(min, max, delta), min, max);
    }

    template<std::floating_point T>
    [[nodiscard]] static constexpr T smoothStep(T x, T edge0 = 0, T edge1 = 1) noexcept
    {
        // From: https://en.wikipedia.org/wiki/Smoothstep

        x = std::clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);

        return x * x * (3 - 2 * x);
    }

    template<std::floating_point T>
    [[nodiscard]] static constexpr T smootherStep(T x, T edge0 = 0, T edge1 = 1) noexcept
    {
        // From: https://en.wikipedia.org/wiki/Smoothstep

        x = std::clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);

        return x * x * x * (x * (x * 6 - 15) + 10);
    }

    template<std::floating_point T>
    [[nodiscard]] static constexpr bool nearlyEqual(T a, T b, T tolerance = std::numeric_limits<T>::epsilon()) noexcept
    {
        return std::abs(a - b) <= tolerance;
    }
};
}  // namespace utils
