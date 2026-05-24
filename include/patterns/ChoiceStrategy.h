#ifndef TRANSITTYCOON_CHOICESTRATEGY_H
#define TRANSITTYCOON_CHOICESTRATEGY_H

#pragma once

#include "transport/TransportMode.h"
#include <memory>
#include <vector>

class Person;

class ChoiceStrategy {
public:
    virtual ~ChoiceStrategy() = default;

    virtual int choose(const Person& person, const std::vector<std::shared_ptr<TransportMode>>& options) = 0;

    virtual const char* name() const = 0;
};

#endif