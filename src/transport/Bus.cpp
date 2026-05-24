#include "../include/transport/Bus.h"

Bus::Bus(int capacity, int price)
    : TransportMode("Autobuz", capacity, price) {}

void Bus::onWeatherChanged(WeatherType w) {
    switch (w) {
        case WeatherType::Snowy: weatherMultiplier = 0.6f; break;
        case WeatherType::Rainy: weatherMultiplier = 0.8f; break;
        default: weatherMultiplier = 1.0f; break;
    }
}