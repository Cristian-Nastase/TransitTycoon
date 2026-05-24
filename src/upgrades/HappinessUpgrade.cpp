#include "upgrades/HappinessUpgrade.h"
#include "core/Game.h"

HappinessUpgrade::HappinessUpgrade(std::string name, int price, int boost)
    : Upgrade(std::move(name), price), boostAmount(boost) {}

void HappinessUpgrade::apply(Game& game) {
    game.queueHappinessBoost(5, boostAmount);
}

std::string HappinessUpgrade::describe() const {
    return "+" + std::to_string(boostAmount) + " mood pentru 5 pasageri viitori";
}