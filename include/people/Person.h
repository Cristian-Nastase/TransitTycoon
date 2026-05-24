#ifndef TRANSITTYCOON_PERSON_H
#define TRANSITTYCOON_PERSON_H

#pragma once

#include "../transport/TransportMode.h"
#include "../patterns/ChoiceStrategy.h"
#include <map>
#include <memory>
#include <string>
#include <ostream>

class Person {
    std::string name;
    std::map<TransportType, float> preferences;
    int mood;
    int budget;
    int boost;
    std::unique_ptr<ChoiceStrategy> strategy;

public:
    Person(std::string name,
           std::map<TransportType, float> preferences,
           int mood,
           int budget,
           std::unique_ptr<ChoiceStrategy> strategy);

    Person(const Person&) = delete;
    Person& operator=(const Person&) = delete;
    Person(Person&&) = default;
    Person& operator=(Person&&) = default;
    ~Person() = default;

    const std::string& getName() const { return name; }
    float getPreference(TransportType t) const;
    int getMood() const { return mood + boost; }
    int getBaseMood() const { return mood; }
    int getBudget() const { return budget; }

    void addBoost(int amount) { boost += amount; }
    void clearBoost() { boost = 0; }

    int chooseTransport(const std::vector<std::shared_ptr<TransportMode>>& options) const;

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif