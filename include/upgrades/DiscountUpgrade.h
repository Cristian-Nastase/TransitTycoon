#ifndef TRANSITTYCOON_DISCOUNTUPGRADE_H
#define TRANSITTYCOON_DISCOUNTUPGRADE_H

#pragma once

#include "upgrades/Upgrade.h"

class DiscountUpgrade : public Upgrade {
    float discountPercent;
public:
    DiscountUpgrade(std::string name, int price, float percent);
    void apply(Game& game) override;
    std::string describe() const override;
};

#endif