#include "../include/upgrades/CapacityUpgrade.h"
#include "../include/core/Game.h"

CapacityUpgrade::CapacityUpgrade(std::string name, int price,
                                  TransportType target, int amount)
    : Upgrade(std::move(name), price), target(target), amount(amount) {}

void CapacityUpgrade::apply(Game& game) {
    auto mode = game.getTransport(target);
    if (mode) {
        mode->increaseCapacity(amount);
    }
}

std::string CapacityUpgrade::describe() const {
    std::string targetName;
    switch (target) {
        case TransportType::Metro:   targetName = "metrou"; break;
        case TransportType::Tram:    targetName = "tramvai"; break;
        case TransportType::Bus:     targetName = "autobuz"; break;
        case TransportType::Walking: targetName = "trotuar"; break;
    }
    return "+" + std::to_string(amount) + " capacitate la " + targetName;
}