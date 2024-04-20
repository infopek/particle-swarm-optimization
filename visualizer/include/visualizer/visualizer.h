#pragma once

#include <pso/particle_swarm_optimization.h>
#include <pso/function_approximation.h>

#include <SFML/Graphics.hpp>

namespace vis
{
    class Visualizer
    {
    public:
        Visualizer(core::ParticleSwarmOptimization& pso, const core::FunctionApproximation& fa);
        ~Visualizer();

        void draw();

    private:
        void drawFunctionPoints();
        void drawApproximation();
        void drawCoordinateSystem();

        void displayStats();

    private:
        core::ParticleSwarmOptimization& m_pso;
        core::FunctionApproximation m_fa;

        sf::RenderWindow m_window;

        sf::Font m_font;
    };
}