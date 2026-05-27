#ifndef TRANSITTYCOON_ROUNDRESULT_H
#define TRANSITTYCOON_ROUNDRESULT_H

#pragma once

#include <iostream>

struct RoundResult {
    int roundNumber;
    int totalPassengers;
    int satisfiedPassengers;
    float averageHappiness;
    int revenue;

    friend std::ostream& operator<<(std::ostream& os, const RoundResult& r);
};

#endif