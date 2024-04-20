#include <common/search_space.h>
#include <common/random.h>

#include <pso/function_approximation.h>
#include <pso/particle_swarm_optimization.h>
#include <pso/parameter.h>

#include <visualizer/visualizer.h>

using namespace core;
using namespace vis;

std::vector<ValuePair> generateValues(const SearchSpace& searchSpace, int numValues)
{
    std::vector<ValuePair> values{};
    for (int i = 0; i < numValues; ++i)
    {
        ValuePair pair{
            .input = random::get<float>(searchSpace.pos.min, searchSpace.pos.max),
            .output = random::get<float>(searchSpace.pos.min, searchSpace.pos.max)
        };

        values.push_back(pair);
    }

    return values;
}

int main()
{
    // Leave these on low values so totalDiff in FunctionApproximation doesn't overflow
    const SearchSpace searchSpace{
        .pos = Interval {
            .min = -6.0f,
            .max = 6.0f
        },
        .vel = Interval {
            .min = -4.0f,
            .max = 4.0f
        }
    };

    const int numValues = 20;
    const std::vector<ValuePair> values = generateValues(searchSpace, numValues);
    FunctionApproximation fa(values);

    Parameter parameter{};
    ParticleSwarmOptimization pso(fa, searchSpace, parameter);

    Visualizer visualizer(pso, fa);
    visualizer.draw();
}
