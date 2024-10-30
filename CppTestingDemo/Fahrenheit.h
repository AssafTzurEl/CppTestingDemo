#pragma once

class Celsius;

class Fahrenheit
{
private:
    double m_degrees;

public:
    Fahrenheit(double degrees = 0.0);
    explicit Fahrenheit(const Celsius &celsius);  // Conversion constructor

    double GetDegrees() const;
    void SetDegrees(double degrees);

    Celsius ToCelsius() const;
    operator Celsius() const;  // Casting operator

    bool operator==(const Fahrenheit &other) const;
    bool operator<(const Fahrenheit &other) const;
    bool operator>(const Fahrenheit &other) const;
    bool operator<=(const Fahrenheit &other) const;
    bool operator>=(const Fahrenheit &other) const;
};

