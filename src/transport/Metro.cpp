#include "../include/transport/Metro.h"

Metro::Metro(int capacity, int price)
    : TransportMode("Metrou", capacity, price) {}

void Metro::onWeatherChanged(WeatherType w) {
// e subteran nu conteaza
    weatherMultiplier = 1.0f;
}