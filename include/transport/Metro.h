#ifndef TRANSITTYCOON_METRO_H
#define TRANSITTYCOON_METRO_H

#pragma once
#include "TransportMode.h"

class Metro : public TransportMode {
public:
    Metro(int capacity, int price);

    TransportType getType() const override { return TransportType::Metro; }
    float baseAttractiveness() const override { return 0.7f; }

    void onWeatherChanged(WeatherType w) override;
};

#endif