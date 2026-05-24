#ifndef TRANSITTYCOON_CAPACITYUPGRADE_H
#define TRANSITTYCOON_CAPACITYUPGRADE_H

#pragma once

#include "upgrades/Upgrade.h"
#include "transport/TransportMode.h"

class CapacityUpgrade : public Upgrade {
    TransportType target;
    int amount;
public:
    CapacityUpgrade(std::string name, int price, TransportType target, int amount);
    void apply(Game& game) override;
    std::string describe() const override;
};

#endif