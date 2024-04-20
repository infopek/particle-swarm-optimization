#include <pso/parameter.h>

namespace core
{
    Parameter::Parameter()
    {
    }

    Parameter::~Parameter()
    {
    }

    void Parameter::setSwarmSize(size_t value)
    {
        if (value > 0)
            m_swarmSize = value;
    }

    void Parameter::setOmega(float value)
    {
        m_omega = value;
    }

    void Parameter::setPhiLocal(float value)
    {
        m_phiLocal = value;
    }

    void Parameter::setPhiGlobal(float value)
    {
        m_phiGlobal = value;
    }
}