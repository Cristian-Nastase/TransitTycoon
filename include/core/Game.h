#ifndef TRANSITTYCOON_GAME_H
#define TRANSITTYCOON_GAME_H

#pragma once

#include "ConfigLoader.h"
#include "WeatherSystem.h"
#include "RoundResult.h"
#include "transport/TransportMode.h"
#include "transport/Walking.h"
#include "people/Person.h"
#include "upgrades/Upgrade.h"
#include "templates/Repository.h"

#include <memory>
#include <vector>

class Game {
    std::unique_ptr<ConfigLoader> config;
    std::unique_ptr<WeatherSystem> weather;

    std::vector<std::shared_ptr<TransportMode>> transports;
    std::shared_ptr<Walking> walkingRef;

    Repository<std::unique_ptr<Upgrade>> availableUpgrades;
    Repository<RoundResult> history;

    Repository<std::shared_ptr<Person>> currentPassengers;

    int money;
    int round;
    float minHappiness;
    int passengersPerRound;
    int revenuePerHappy;

    int pendingBoostCount;
    int pendingBoostAmount;

    void loadConfig(const std::string& configFile);
    void createTransports();

public:
    Game(const std::string& configFile, const std::string& upgradesFile);
    ~Game() = default;

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    RoundResult runRound();
    void applyUpgrade(std::size_t index);  // throws InsufficientFundsException

    std::shared_ptr<TransportMode> getTransport(TransportType t);
    std::shared_ptr<Walking> getWalking() { return walkingRef; }
    void queueHappinessBoost(int count, int amount);

    int getMoney() const { return money; }
    int getRound() const { return round; }
    float getMinHappiness() const { return minHappiness; }
    WeatherType getCurrentWeather() const { return weather->getCurrent(); }

    const std::vector<std::shared_ptr<TransportMode>>& getTransports() const {
        return transports;
    }
    const Repository<std::unique_ptr<Upgrade>>& getUpgrades() const {
        return availableUpgrades;
    }
    const Repository<RoundResult>& getHistory() const {
        return history;
    }

    const Repository<std::shared_ptr<Person>>& getCurrentPassengers() const {
        return currentPassengers;
    }

};

#endif