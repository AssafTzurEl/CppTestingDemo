#pragma once

#include <exception>
#include <string>

class TemperatureException : public std::exception
{
public:
    TemperatureException(const std::string &message)
        : m_message(message)
    {}

    TemperatureException(double degrees)
        : m_message("Invalid temperature: " + std::to_string(degrees))
    {}

    const char* what() const noexcept
    {
        return m_message.c_str();
    }

private:
    std::string m_message;
};