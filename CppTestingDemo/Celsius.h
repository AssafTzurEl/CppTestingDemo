#pragma once

class Fahrenheit;

class Celsius
{
private:
    double m_degrees;

public:
    Celsius(double degrees = 0.0);
    explicit Celsius(const Fahrenheit &fahrenheit);  // Conversion constructor

    double GetDegrees() const;
    void SetDegrees(double degrees);

    Fahrenheit ToFahrenheit() const;
    operator Fahrenheit() const;  // Casting operator

    bool operator==(const Celsius &other) const;
    bool operator<(const Celsius &other) const;
    bool operator>(const Celsius &other) const;
    bool operator<=(const Celsius &other) const;
    bool operator>=(const Celsius &other) const;
};