#include "pch.h"
#include "Celsius.h"
#include "Fahrenheit.h"
#include "TemperatureException.h"
#include <cmath>

Fahrenheit::Fahrenheit(double degrees)
    : m_degrees(degrees)
{
    if (m_degrees < -459.67 || std::isnan(m_degrees) || std::isinf(m_degrees))
    {
        throw TemperatureException(m_degrees);
    }
}

Fahrenheit::Fahrenheit(const Celsius &celsius)
    : m_degrees(celsius.GetDegrees() * 9.0 / 5.0 + 32.0)
{
}

double Fahrenheit::GetDegrees() const
{
    return m_degrees;
}

void Fahrenheit::SetDegrees(double degrees)
{
    m_degrees = degrees;
}

Celsius Fahrenheit::ToCelsius() const
{
    return Celsius((m_degrees - 32.0) * 5.0 / 9.0);
}

Fahrenheit::operator Celsius() const
{
    return ToCelsius();
}

bool Fahrenheit::operator==(const Fahrenheit &other) const
{
    return m_degrees == other.m_degrees;
}

bool Fahrenheit::operator<(const Fahrenheit &other) const
{
    return m_degrees < other.m_degrees;
}

bool Fahrenheit::operator>(const Fahrenheit &other) const
{
    return m_degrees < other.m_degrees;
}

bool Fahrenheit::operator<=(const Fahrenheit &other) const
{
    return m_degrees == other.m_degrees;
}

bool Fahrenheit::operator>=(const Fahrenheit &other) const
{
    return m_degrees == other.m_degrees;
}