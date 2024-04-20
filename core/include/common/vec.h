#pragma once

#include <vector>

namespace core
{
    inline constexpr size_t numCoefficients = 5;

    struct Vec
    {
        float coords[5]{};

        Vec& operator+=(const Vec& other)
        {
            for (size_t i = 0; i < numCoefficients; i++)
                coords[i] += other.coords[i];

            return *this;
        }

        Vec operator+(const Vec& other) const
        {
            Vec res{};
            for (size_t i = 0; i < numCoefficients; i++)
                res.coords[i] = coords[i] + other.coords[i];

            return res;
        }

        Vec operator-(const Vec& other) const
        {
            Vec res{};
            for (size_t i = 0; i < numCoefficients; i++)
                res.coords[i] = coords[i] - other.coords[i];

            return res;
        }

        Vec operator*(float scalar) const
        {
            Vec res{};
            for (size_t i = 0; i < numCoefficients; i++)
                res.coords[i] = coords[i] * scalar;

            return res;
        }

        friend Vec operator*(float scalar, const Vec& vec)
        {
            return vec * scalar;
        }
    };
}