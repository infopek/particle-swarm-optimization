#include <pso/particle_swarm_optimization.h>
#include <common/random.h>

namespace core
{
    ParticleSwarmOptimization::ParticleSwarmOptimization(const FunctionApproximation& fa, const SearchSpace& searchSpace, const Parameter& parameter)
        : m_fa{ fa }, m_searchSpace{ searchSpace }, m_parameter{ parameter }
    {
        initSwarm();
        evaluate();
    }

    ParticleSwarmOptimization::~ParticleSwarmOptimization()
    {

    }

    void ParticleSwarmOptimization::initSwarm()
    {
        const size_t swarmSize = m_parameter.getSwarmSize();
        m_swarm.particles.resize(swarmSize);
        for (size_t i = 0; i < swarmSize; i++)
        {
            auto& pos = m_swarm.particles[i].pos;
            auto& vel = m_swarm.particles[i].vel;

            for (size_t i = 0; i < numCoefficients; i++)
            {
                pos.coords[i] = random::get(m_searchSpace.pos.min, m_searchSpace.pos.max);
                vel.coords[i] = random::get(m_searchSpace.vel.min, m_searchSpace.vel.max);
            }
        }

    }

    void ParticleSwarmOptimization::step()
    {
        calculateVelocity();

        for (auto& particle : m_swarm.particles)
            particle.pos += particle.vel;

        evaluate();
    }

    void ParticleSwarmOptimization::evaluate()
    {
        for (auto& particle : m_swarm.particles)
        {
            if (fitness(particle.pos) < fitness(particle.opt))
            {
                particle.opt = particle.pos;
                if (fitness(particle.pos) < fitness(m_swarm.globalOpt))
                {
                    m_swarm.globalOpt = particle.pos;
                }
            }
        }

    }

    void ParticleSwarmOptimization::calculateVelocity()
    {
        for (auto& particle : m_swarm.particles)
        {
            float rand1 = random::get<float>(0.0f, 1.0f);
            float rand2 = random::get<float>(0.0f, 1.0f);

            particle.vel = m_parameter.getOmega() * particle.vel
                + m_parameter.getPhiLocal() * rand1 * (particle.opt - particle.pos)
                + m_parameter.getPhiGlobal() * rand2 * (m_swarm.globalOpt - particle.pos);

        }
    }

    float ParticleSwarmOptimization::fitness(const Vec& position) const
    {
        return m_fa.objective(std::vector<float>(position.coords, position.coords + numCoefficients));
    }
}