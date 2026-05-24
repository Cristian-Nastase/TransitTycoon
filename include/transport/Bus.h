#ifndef TRANSITTYCOON_BUS_H
#define TRANSITTYCOON_BUS_H

#pragma once

#include "TransportMode.h"

class Bus : public TransportMode {
public:
    Bus(int capacity, int price);

    TransportType getType() const override { return TransportType::Bus; }
    float baseAttractiveness() const override { return 0.5f; }

    void onWeatherChanged(WeatherType w) override;
};

#endif