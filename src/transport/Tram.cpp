#include "../include/transport/Tram.h"

Tram::Tram(int capacity, int price)
    : TransportMode("Tramvai", capacity, price) {}

void Tram::onWeatherChanged(WeatherType w) {
    // tramvaiul merge mai prost la ninsoare si ploaie
    switch (w) {
        case WeatherType::Snowy: weatherMultiplier = 0.7f; break;
        case WeatherType::Rainy: weatherMultiplier = 0.9f; break;
        default: weatherMultiplier = 1.0f; break;
    }
}