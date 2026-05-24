#include "core/RandomGenerator.h"

#pragma once

#include <numeric>
#include <stdexcept>

RandomGenerator::RandomGenerator()
    : engine(std::random_device{}()) {}

RandomGenerator& RandomGenerator::getInstance() {
    static RandomGenerator instance;
    return instance;
}

int RandomGenerator::intInRange(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(engine);
    }

float RandomGenerator::floatInRange(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(engine);
}

bool RandomGenerator::chance(float probability) {
    return floatInRange(0.0f, 1.0f) < probability;
}

std::size_t RandomGenerator::weightedChoice(const std::vector<float>& weights) {
    if (weights.empty()) {
        throw std::invalid_argument("weightedChoice: weights gol");
    }

    const float total = std::accumulate(weights.begin(), weights.end(), 0.0f);
    if (total <= 0.0f) {
        return 0;
    }

    float roll = floatInRange(0.0f, total);
    float cumulative = 0.0f;

    for (std::size_t i = 0; i < weights.size(); ++i) {
        cumulative += weights[i];
        if (roll <= cumulative) {
            return i;
        }
    }
    return weights.size() - 1;
}
