#include <visualizer/visualizer.h>

#include "render_settings.h"

#include <cmath>

namespace vis
{
    Visualizer::Visualizer(core::ParticleSwarmOptimization& pso, const core::FunctionApproximation& fa)
        : m_pso{ pso },
        m_fa{ fa }
    {
        m_window.create(sf::VideoMode(windowWidth, windowHeight), "Particle Swarm Optimization for function approximation");

        if (!m_font.loadFromFile("../../../visualizer/res/fonts/arial.ttf")) {}
    }

    Visualizer::~Visualizer()
    {
    }

    void Visualizer::draw()
    {
        while (m_window.isOpen())
        {
            sf::Event event;
            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_window.close();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                {
                    m_pso.step();
                }
            }

            m_window.clear(sf::Color::White);

            drawCoordinateSystem();
            drawFunctionPoints();
            drawApproximation();

            displayStats();

            m_window.display();
        }
    }

    void Visualizer::drawApproximation()
    {
        sf::VertexArray parabola(sf::LineStrip);

        const auto* coords = m_pso.getSwarm().globalOpt.coords;
        std::vector<float> coefs = std::vector<float>(coords, coords + core::numCoefficients);

        for (float x = -10.0f; x <= 10.0f; x += 0.1f)
        {
            float y = coefs[0] * pow(x - coefs[1], 3)
                + coefs[2] * pow(x - coefs[3], 2)
                + coefs[4] * x;

            float scaledX = x * scaleX + translateX;
            float scaledY = -y * scaleY + translateY;

            parabola.append(sf::Vertex(sf::Vector2f(scaledX, scaledY), sf::Color::Blue));
        }

        parabola.setPrimitiveType(sf::LinesStrip);

        m_window.draw(parabola);
    }

    void Visualizer::drawFunctionPoints()
    {
        sf::CircleShape point(3.0f);
        point.setFillColor(sf::Color::Red);

        const auto& data = m_fa.getData();

        for (const auto& pointData : data)
        {
            float scaledX = pointData.input * scaleX + translateX;
            float scaledY = -pointData.output * scaleY + translateY;

            point.setPosition(scaledX, scaledY);
            m_window.draw(point);
        }
    }

    void Visualizer::drawCoordinateSystem()
    {
        sf::VertexArray axes(sf::Lines, 4);

        // X-axis
        axes[0].position = sf::Vector2f(0, windowHeight / 2.0f);
        axes[1].position = sf::Vector2f(windowWidth, windowHeight / 2.0f);

        // Y-axis
        axes[2].position = sf::Vector2f(windowWidth / 2.0f, 0);
        axes[3].position = sf::Vector2f(windowWidth / 2.0f, windowHeight);

        for (int i = 0; i < 4; ++i)
            axes[i].color = sf::Color::Black;

        m_window.draw(axes);

        // Draw labels
        sf::Text xLabel("+X", m_font);
        xLabel.setCharacterSize(12);
        xLabel.setFillColor(sf::Color::Black);
        xLabel.setPosition(windowWidth - 20, windowHeight / 2.0f + 10); // Adjusted position

        sf::Text yLabel("+Y", m_font);
        yLabel.setCharacterSize(12);
        yLabel.setFillColor(sf::Color::Black);
        yLabel.setPosition(windowWidth / 2.0f + 10, 10);

        m_window.draw(xLabel);
        m_window.draw(yLabel);

        // Number on the axes
        sf::Text numberLabel;
        numberLabel.setFont(m_font);
        numberLabel.setCharacterSize(12);
        numberLabel.setFillColor(sf::Color::Black);

        // Draw numerical labels along the X-axis
        for (int x = -10; x <= 10; ++x)
        {
            numberLabel.setString(std::to_string(x));
            numberLabel.setPosition(x * (windowWidth / 20.0f) + windowWidth / 2.0f - 5, windowHeight / 2.0f + 10);
            m_window.draw(numberLabel);
        }

        // Draw numerical labels along the Y-axis
        for (int y = -10; y <= 10; ++y)
        {
            numberLabel.setString(std::to_string(y));
            numberLabel.setPosition(windowWidth / 2.0f + 10, y * (windowHeight / 20.0f) - 5 + windowHeight / 2.0f);
            m_window.draw(numberLabel);
        }
    }

    void Visualizer::displayStats()
    {
        const auto* coords = m_pso.getSwarm().globalOpt.coords;
        std::vector<float> coefs(coords, coords + core::numCoefficients);

        sf::Text coefficientText;
        coefficientText.setFont(m_font);
        coefficientText.setCharacterSize(16);
        coefficientText.setFillColor(sf::Color::Black);

        const float textPaddingX = 170.0f;
        const float textPaddingY = 20.0f;
        sf::Vector2f textPosition(windowWidth - textPaddingX, 0.0f + textPaddingY);

        for (size_t i = 0; i < coefs.size(); ++i)
        {
            coefficientText.setString("Coefficient " + std::to_string(i) + ": " + std::to_string(coefs[i]));
            coefficientText.setPosition(textPosition.x, textPosition.y + i * 20.0f);
            m_window.draw(coefficientText);
        }
    }
}
