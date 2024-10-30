#pragma once

#include "Celsius.h"
#include <memory>

class IHeatingElement;

class Thermostat
{
public:
    Thermostat(std::unique_ptr<IHeatingElement> heatingElement,
        const Celsius &upperThreshold,
        const Celsius &lowerThreshold);

    void OnTemperatureMeasured(Celsius temperature);

private:
    std::unique_ptr<IHeatingElement> m_heatingElement;
    Celsius m_upperThreshold;
    Celsius m_lowerThreshold;
};

