#ifndef TRANSITTYCOON_IOBSERVER_H
#define TRANSITTYCOON_IOBSERVER_H

#pragma once

enum class WeatherType {
    Sunny,
    Cloudy,
    Rainy,
    Snowy
};

class IObserver {
public:
    virtual void onWeatherChanged(WeatherType newWeather) = 0;
    virtual ~IObserver() = default;
};

#endif