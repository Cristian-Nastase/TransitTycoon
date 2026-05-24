#include "../include/core/Game.h"
#include "../include/core/RandomGenerator.h"
#include "../include/transport/Metro.h"
#include "../include/transport/Tram.h"
#include "../include/transport/Bus.h"
#include "../include/people/PersonFactory.h"
#include "../include/upgrades/UpgradeFactory.h"
#include "../include/exceptions/GameExceptions.h"

Game::Game(const std::string& configFile, const std::string& upgradesFile)
    : pendingBoostCount(0), pendingBoostAmount(0) {

    loadConfig(configFile);
    createTransports();

    weather = std::make_unique<WeatherSystem>(
        config->getFloat("weather_change_probability"));

    for (auto& t : transports) {
        weather->attach(t);
    }

    availableUpgrades = UpgradeFactory::loadFromFile(upgradesFile);
}

void Game::loadConfig(const std::string& configFile) {
    config = std::make_unique<ConfigLoader>(configFile);

    money = config->getInt("starting_money");
    round = 0;
    minHappiness = config->getFloat("min_happiness");
    passengersPerRound = config->getInt("passengers_per_round");
    revenuePerHappy = config->getInt("revenue_per_happy_passenger");
}

void Game::createTransports() {
    transports.push_back(std::make_shared<Metro>(
        config->getInt("metro_capacity"), config->getInt("metro_price")));
    transports.push_back(std::make_shared<Tram>(
        config->getInt("tram_capacity"), config->getInt("tram_price")));
    transports.push_back(std::make_shared<Bus>(
        config->getInt("bus_capacity"), config->getInt("bus_price")));

    auto walking = std::make_shared<Walking>(
        config->getInt("walking_capacity"), config->getInt("walking_price"));
    walkingRef = walking;
    transports.push_back(walking);
}

std::shared_ptr<TransportMode> Game::getTransport(TransportType t) {
    for (auto& mode : transports) {
        if (mode->getType() == t) return mode;
    }
    return nullptr;
}

void Game::queueHappinessBoost(int count, int amount) {
    pendingBoostCount = count;
    pendingBoostAmount = amount;
}

RoundResult Game::runRound() {
    ++round;

    weather->advance();

    for (auto& t : transports) t->resetLoad();

    Repository<std::shared_ptr<Person>> passengers;
    for (int i = 0; i < passengersPerRound; ++i) {
        auto p = PersonFactory::createRandom(round * 1000 + i);
        if (pendingBoostCount > 0) {
            p->addBoost(pendingBoostAmount);
            --pendingBoostCount;
        }
        passengers.add(std::move(p));
    }

    int satisfied = 0;
    float happinessSum = 0.0f;
    int revenue = 0;

    passengers.forEach([&](std::shared_ptr<Person>& person) {
        int idx = person->chooseTransport(transports);

        if (idx >= 0 && idx < static_cast<int>(transports.size())) {
            auto& chosen = transports[idx];
            if (chosen->hasRoom()) {
                chosen->board();
                ++satisfied;
                happinessSum += static_cast<float>(person->getMood());
                revenue += chosen->getTicketPrice();
            } else {
                // a ales ceva plin = furios
                happinessSum += static_cast<float>(person->getMood()) * 0.3f;
            }
        } else {
            // niciun transport valabil = foarte suparat
            happinessSum += static_cast<float>(person->getMood()) * 0.1f;
        }
    });

    float maxPossible = static_cast<float>(passengersPerRound * 100);
    float avgHappiness = (maxPossible > 0)
        ? (happinessSum / maxPossible) * 100.0f
        : 0.0f;

    revenue += satisfied * revenuePerHappy;
    money += revenue;

    RoundResult result{round, passengersPerRound, satisfied,
                       avgHappiness, revenue};
    history.add(result);

    if (avgHappiness < minHappiness) {
        throw GameOverException("Fericirea " + std::to_string(avgHappiness)
                                + "% a cazut sub "
                                + std::to_string(minHappiness) + "%");
    }

    return result;
}

void Game::applyUpgrade(std::size_t index) {
    if (index >= availableUpgrades.size()) {
        throw InvalidChoiceException("Index invalid: " + std::to_string(index));
    }

    auto& upgrade = availableUpgrades.at(index);
    if (money < upgrade->getPrice()) {
        throw InsufficientFundsException(upgrade->getPrice(), money);
    }

    money -= upgrade->getPrice();
    upgrade->apply(*this);
}