#include "upgrades/UmbrellaUpgrade.h"
#include "core/Game.h"
#include "transport/Walking.h"

UmbrellaUpgrade::UmbrellaUpgrade(std::string name, int price, float bonus)
    : Upgrade(std::move(name), price), effectBonus(bonus) {}

void UmbrellaUpgrade::apply(Game& game) {
    auto walking = game.getWalking();
    if (walking) {
        walking->giveUmbrellas();
    }
}

std::string UmbrellaUpgrade::describe() const {
    return "Umbrele pentru pietoni (anuleaza penalty mare la ploaie)";
}