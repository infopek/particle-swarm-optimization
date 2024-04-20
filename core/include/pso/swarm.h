#pragma once

#include <pso/particle.h>

#include <vector>

namespace core
{
    struct Swarm
    {
        std::vector<Particle> particles{};
        Vec globalOpt{};
    };
}
