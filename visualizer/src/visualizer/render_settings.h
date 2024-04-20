#pragma once

namespace vis
{
    inline constexpr unsigned int windowWidth = 1200;
    inline constexpr unsigned int windowHeight = 800;

    inline constexpr float translateX = static_cast<float>(windowWidth) / 2.0f;
    inline constexpr float translateY = static_cast<float>(windowHeight) / 2.0f;

    inline constexpr float scaleX = windowWidth / 20.0f;
    inline constexpr float scaleY = windowHeight / 20.0f;
}