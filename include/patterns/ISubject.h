#ifndef TRANSITTYCOON_ISUBJECT_H
#define TRANSITTYCOON_ISUBJECT_H

#pragma once

#include "IObserver.h"
#include <memory>
#include <vector>

class ISubject {
protected:
    std::vector<std::weak_ptr<IObserver>> observers;

public:
    virtual ~ISubject() = default;

    void attach(std::shared_ptr<IObserver> obs) {
        observers.push_back(obs);
    }

    void notifyAll(WeatherType weather) {
        auto it = observers.begin();
        while (it != observers.end()) {
            if (auto alive = it->lock()) {
                alive->onWeatherChanged(weather);
                ++it;
            } else {
                it = observers.erase(it);
            }
        }
    }
};

#endif