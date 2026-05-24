#ifndef TRANSITTYCOON_TRANSPORTMODE_H
#define TRANSITTYCOON_TRANSPORTMODE_H

#pragma once

#include <memory>
#include "patterns/IObserver.h"
#include <string>

enum class TransportType {
    Metro,
    Tram,
    Bus,
    Walking
};

class TransportMode : public IObserver,
                       public std::enable_shared_from_this<TransportMode> {
protected:
    std::string name;
    int capacity;
    int currentLoad;
    int ticketPrice;
    float weatherMultiplier;

public:
    TransportMode(std::string name, int capacity, int ticketPrice);
    ~TransportMode() override = default;

    const std::string& getName() const { return name; }
    int getCapacity() const { return capacity; }
    int getLoad() const { return currentLoad; }
    int getTicketPrice() const { return ticketPrice; }
    float getWeatherMultiplier() const { return weatherMultiplier; }

    bool hasRoom() const { return currentLoad < capacity; }
    void board() { if (hasRoom()) ++currentLoad; }
    void resetLoad() { currentLoad = 0; }

    void increaseCapacity(int amount) { capacity += amount; }
    void applyDiscount(float percent);

    virtual TransportType getType() const = 0;
    virtual float baseAttractiveness() const = 0;

    void onWeatherChanged(WeatherType w) override = 0;
};

#endif