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

#include <utils/Macros.hpp>

#include <optional>

namespace utils {

struct NotCopyable
{
    NotCopyable() = default;

    NotCopyable(const NotCopyable&) = delete;
    NotCopyable& operator=(const NotCopyable&) = delete;
};

struct NotMovable
{
    NotMovable() = default;

    NotMovable(NotMovable&&) = delete;
    NotMovable& operator=(NotMovable&&) = delete;
};

/**
 * Forces a compile error and shows the type of a variable.
 * Useful tool when searching for an auto type or deep library calls.
 * Inspired from Scott Meyers' Effective C++ book.
 * @tparam T Type you are looking for, use decltype of the variable to detect it.
 */
template<typename T>
class [[maybe_unused]] TypeChecker;

/**
 * Run a functor when on scope exit.
 * Intended to be used with the `ON_SCOPE_EXIT` macro.
 * @tparam Func
 */
template<typename Func>
class ScopeExitFunctor final
{
public:
    explicit ScopeExitFunctor(Func&& func) : m_func{std::move(func)} {}
    ~ScopeExitFunctor() { m_func(); }

private:
    Func m_func;
};

namespace detail {
    struct ScopeExitHelper final
    {
        template<typename Func>
        ScopeExitFunctor<Func> operator+(Func&& func) noexcept
        {
            return ScopeExitFunctor<Func>{std::forward<Func>(func)};
        }
    };
}  // namespace detail

/**
 * Executes a lambda when the scope exits.
 */
#define ON_SCOPE_EXIT                                          \
    const auto& UTILS_STRCAT(_SCOPE_EXIT_FUNC_, __COUNTER__) = \
      utils::detail::ScopeExitHelper{} + [&]()  // NOLINT(bugprone-macro-parentheses)

}  // namespace utils
