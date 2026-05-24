#include "upgrades/DiscountUpgrade.h"
#include "transport/TransportMode.h"
#include "core/Game.h"

DiscountUpgrade::DiscountUpgrade(std::string name, int price, float percent)
    : Upgrade(std::move(name), price), discountPercent(percent) {}

void DiscountUpgrade::apply(Game& game) {
    for (auto type : {TransportType::Metro, TransportType::Tram,
                       TransportType::Bus, TransportType::Walking}) {
        auto mode = game.getTransport(type);
        if (mode) mode->applyDiscount(discountPercent);
                       }
}

std::string DiscountUpgrade::describe() const {
    int pct = static_cast<int>(discountPercent * 100);
    return "Reducere " + std::to_string(pct) + "% la toate biletele";
}