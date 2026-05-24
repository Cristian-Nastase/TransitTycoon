#ifndef TRANSITTYCOON_TRAM_H
#define TRANSITTYCOON_TRAM_H

#pragma once

#include "TransportMode.h"

class Tram : public TransportMode {
public:
    Tram(int capacity, int price);

    TransportType getType() const override { return TransportType::Tram; }
    float baseAttractiveness() const override { return 0.6f; }

    void onWeatherChanged(WeatherType w) override;
};
#endif