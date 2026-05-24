#ifndef TRANSITTYCOON_UMBRELLAUPGRADE_H
#define TRANSITTYCOON_UMBRELLAUPGRADE_H

#pragma once

#include "upgrades/Upgrade.h"

class UmbrellaUpgrade : public Upgrade {
    float effectBonus;
public:
    UmbrellaUpgrade(std::string name, int price, float bonus);
    void apply(Game& game) override;
    std::string describe() const override;
};

#endif