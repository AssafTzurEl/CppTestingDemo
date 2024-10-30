#include "pch.h"
#include "IHeatingElement.h"
#include "Thermostat.h"

Thermostat::Thermostat(std::unique_ptr<IHeatingElement> heatingElement,
    const Celsius &upperThreshold,
    const Celsius &lowerThreshold)
    : m_heatingElement(std::move(heatingElement)),
      m_upperThreshold(upperThreshold),
      m_lowerThreshold(lowerThreshold)
{
}

void Thermostat::OnTemperatureMeasured(Celsius temperature)
{
    if (temperature < m_lowerThreshold && !m_heatingElement->IsOn())
    {
        m_heatingElement->TurnOn();
    }
    else if (temperature >= m_upperThreshold && m_heatingElement->IsOn())
    {
        m_heatingElement->TurnOff();
    }
}
