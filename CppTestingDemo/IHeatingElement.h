#pragma once

class IHeatingElement
{
public:
    virtual ~IHeatingElement() = default;

    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
    virtual bool IsOn() const = 0;
};

