#ifndef TRANSITTYCOON_WALKING_H
#define TRANSITTYCOON_WALKING_H

#pragma once

#include "TransportMode.h"

class Walking : public TransportMode {
    bool hasUmbrellas;

public:
    Walking(int capacity, int price);

    TransportType getType() const override { return TransportType::Walking; }
    float baseAttractiveness() const override { return 0.3f; }

    void onWeatherChanged(WeatherType w) override;
    void giveUmbrellas() { hasUmbrellas = true; }
    bool hasUmbrellasAvailable() const { return hasUmbrellas; }
};

#endif