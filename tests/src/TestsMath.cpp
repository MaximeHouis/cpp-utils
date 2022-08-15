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

#include <gtest/gtest.h>
#include <utils/Math.hpp>

using utils::Math;

TEST(Math, Lerp)
{
    EXPECT_FLOAT_EQ(Math::lerp(0.f, 1.f, 0.f), 0.f);
    EXPECT_FLOAT_EQ(Math::lerp(0.f, 1.f, 0.5f), 0.5f);
    EXPECT_FLOAT_EQ(Math::lerp(0.f, 1.f, 1.f), 1.f);

    EXPECT_FLOAT_EQ(Math::lerp(-50.f, 50.f, 0.f), -50.f);
    EXPECT_FLOAT_EQ(Math::lerp(-50.f, 50.f, 0.5f), 0.f);
    EXPECT_FLOAT_EQ(Math::lerp(-50.f, 50.f, 1.f), 50.f);

    EXPECT_FLOAT_EQ(Math::lerpClamped(-50.f, 50.f, -20.f), -50.f);
    EXPECT_FLOAT_EQ(Math::lerpClamped(-50.f, 50.f, 1.f), 50.f);
    EXPECT_FLOAT_EQ(Math::lerpClamped(-50.f, 50.f, 10.f), 50.f);
}

TEST(Math, NearlyEqual)
{
    EXPECT_TRUE(Math::nearlyEqual(.1f + .2f, .3f));
    EXPECT_TRUE(Math::nearlyEqual(42.42f - (10.605f * 2.f), 21.21f));
    EXPECT_TRUE(Math::nearlyEqual(100.0, 101.0, 1.0));

    EXPECT_FALSE(Math::nearlyEqual(100.0, 101.0));
    EXPECT_FALSE(Math::nearlyEqual(100.0, 100.0000042));
}
