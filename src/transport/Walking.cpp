#include "transport/Walking.h"

Walking::Walking(int capacity, int price)
    : TransportMode("Pe jos", capacity, price), hasUmbrellas(false) {}

void Walking::onWeatherChanged(WeatherType w) {
    // mersul pe jos e afectat cel mai tare de vreme
    switch (w) {
        case WeatherType::Sunny:
            weatherMultiplier = 1.2f;  // e frumos afara = bonus
            break;
        case WeatherType::Cloudy:
            weatherMultiplier = 0.8f;
            break;
        case WeatherType::Rainy:
            weatherMultiplier = hasUmbrellas ? 0.7f : 0.2f;
            break;
        case WeatherType::Snowy:
            weatherMultiplier = 0.3f;
            break;
    }
}