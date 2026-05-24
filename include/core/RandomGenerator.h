#ifndef TRANSITTYCOON_RANDOMGENERATOR_H
#define TRANSITTYCOON_RANDOMGENERATOR_H

#pragma once

#include <random>
#include <vector>
    class RandomGenerator {
    private:
        std::mt19937 engine;

        RandomGenerator();
    public:
        static RandomGenerator& getInstance();

        RandomGenerator(const RandomGenerator&) = delete;
        RandomGenerator& operator=(const RandomGenerator&) = delete;
        RandomGenerator(RandomGenerator&&) = delete;
        RandomGenerator& operator=(RandomGenerator&&) = delete;

        int intInRange(int min, int max);
        float floatInRange(float min, float max);
        bool chance(float probability);

        std::size_t weightedChoice(const std::vector<float>& weights);
    };

#endif