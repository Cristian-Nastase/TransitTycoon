#ifndef TRANSITTYCOON_WEATHERSYSTEM_H
#define TRANSITTYCOON_WEATHERSYSTEM_H

#pragma once

#include "../patterns/ISubject.h"

class WeatherSystem : public ISubject {
    WeatherType current;
    float changeProbability;

public:
    explicit WeatherSystem(float changeProbability);

    void advance();
    WeatherType getCurrent() const { return current; }

    static const char* weatherName(WeatherType w);
};

#endif