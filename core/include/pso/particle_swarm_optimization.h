#pragma once

#include <common/search_space.h>
#include <pso/function_approximation.h>
#include <pso/parameter.h>
#include <pso/swarm.h>

namespace core
{
    class ParticleSwarmOptimization
    {
    public:
        ParticleSwarmOptimization(const FunctionApproximation& fa, const SearchSpace& searchSpace, const Parameter& parameter);
        ~ParticleSwarmOptimization();

        void step();

        inline const Swarm& getSwarm() const { return m_swarm; }

    private:
        void initSwarm();

        void evaluate();

        void calculateVelocity();

        float fitness(const Vec& position) const;

    private:
        FunctionApproximation m_fa;
        SearchSpace m_searchSpace{};
        Parameter m_parameter{};

        Swarm m_swarm{};
    };
}
