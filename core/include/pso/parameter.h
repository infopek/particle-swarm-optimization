#pragma once

#include "parameter_defaults.h"

namespace core
{
    class Parameter
    {
    public:
        Parameter();
        ~Parameter();

        inline size_t getSwarmSize() const { return m_swarmSize; }
        inline float getOmega() const { return m_omega; }
        inline float getPhiLocal() const { return m_phiLocal; }
        inline float getPhiGlobal() const { return m_phiGlobal; }

        void setSwarmSize(size_t value);
        void setOmega(float value);
        void setPhiLocal(float value);
        void setPhiGlobal(float value);

    private:
        size_t m_swarmSize{ swarmSizeDefault };
        float m_omega{ omegaDefault };
        float m_phiLocal{ phiLocalDefault };
        float m_phiGlobal{ phiGlobalDefault };
    };
}