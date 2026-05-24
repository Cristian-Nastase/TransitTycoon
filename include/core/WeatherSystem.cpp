#include "WeatherSystem.h"
#include "RandomGenerator.h"

WeatherSystem::WeatherSystem(float changeProbability)
    : current(WeatherType::Sunny), changeProbability(changeProbability) {}

void WeatherSystem::advance() {
    auto& rng = RandomGenerator::getInstance();

    if (rng.chance(changeProbability)) {
        WeatherType options[] = {
            WeatherType::Sunny, WeatherType::Cloudy,
            WeatherType::Rainy, WeatherType::Snowy
        };
        WeatherType newWeather;
        do {
            newWeather = options[rng.intInRange(0, 3)];
        } while (newWeather == current);

        current = newWeather;
    }

    notifyAll(current);
}

const char* WeatherSystem::weatherName(WeatherType w) {
    switch (w) {
        case WeatherType::Sunny:  return "Insorit";
        case WeatherType::Cloudy: return "Innorat";
        case WeatherType::Rainy:  return "Ploaie";
        case WeatherType::Snowy:  return "Ninsoare";
    }
    return "?";
}