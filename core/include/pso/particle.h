#pragma once

#include <common/vec.h>

namespace core
{
    struct Particle
    {
        Vec pos{};
        Vec vel{};
        Vec opt{};
    };
}
