#ifndef TRANSITTYCOON_WEIGHTEDRANDOMSTRATEGY_H
#define TRANSITTYCOON_WEIGHTEDRANDOMSTRATEGY_H

#pragma once

#include "ChoiceStrategy.h"

class WeightedRandomStrategy : public ChoiceStrategy {
public:
    int choose(const Person& p,
               const std::vector<std::shared_ptr<TransportMode>>& options) override;
    const char* name() const override { return "WeightedRandom"; }
};

#endif