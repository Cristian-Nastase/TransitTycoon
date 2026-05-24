#ifndef TRANSITTYCOON_CHEAPESTSTRATEGY_H
#define TRANSITTYCOON_CHEAPESTSTRATEGY_H

#pragma once
#include "ChoiceStrategy.h"

class CheapestStrategy : public ChoiceStrategy {
public:
    int choose(const Person& p,
               const std::vector<std::shared_ptr<TransportMode>>& options) override;
    const char* name() const override { return "Cheapest"; }
};

#endif