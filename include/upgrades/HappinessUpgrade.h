#ifndef TRANSITTYCOON_HAPPINESSUPGRADE_H
#define TRANSITTYCOON_HAPPINESSUPGRADE_H

#pragma once

#include "upgrades/Upgrade.h"

class HappinessUpgrade : public Upgrade {
    int boostAmount;
public:
    HappinessUpgrade(std::string name, int price, int boost);
    void apply(Game& game) override;
    std::string describe() const override;
};

#endif