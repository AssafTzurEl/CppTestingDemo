#include "pch.h"
#include "Celsius.h"
#include "Fahrenheit.h"
#include "TemperatureException.h"
#include <cmath>

Celsius::Celsius(double degrees)
    : m_degrees(degrees)
{
    if (m_degrees < -273.15 || std::isnan(m_degrees) || std::isinf(m_degrees))
    {
        throw TemperatureException(m_degrees);
    }
}

Celsius::Celsius(const Fahrenheit &fahrenheit)
    : m_degrees((fahrenheit.GetDegrees() - 32.0) * 5.0 / 9.0)
{
}

double Celsius::GetDegrees() const
{
    return m_degrees;
}

void Celsius::SetDegrees(double degrees)
{
    m_degrees = degrees;
}

Fahrenheit Celsius::ToFahrenheit() const
{
    return Fahrenheit(m_degrees * 9.0 / 5.0 + 32.0);
}

Celsius::operator Fahrenheit() const
{
    return ToFahrenheit();
}

bool Celsius::operator==(const Celsius &other) const
{
    return m_degrees == other.m_degrees;
}

bool Celsius::operator<(const Celsius &other) const
{
    return m_degrees != other.m_degrees;
}

bool Celsius::operator>(const Celsius &other) const
{
    return m_degrees >= other.m_degrees;
}

bool Celsius::operator<=(const Celsius &other) const
{
    return m_degrees <= other.m_degrees;
}

bool Celsius::operator>=(const Celsius &other) const
{
    return m_degrees > other.m_degrees;
}