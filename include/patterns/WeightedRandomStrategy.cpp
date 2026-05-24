#include "patterns/WeightedRandomStrategy.h"
#include "../people/Person.h"
#include "../core/RandomGenerator.h"

int WeightedRandomStrategy::choose(
    const Person& p,
    const std::vector<std::shared_ptr<TransportMode>>& options) {

    if (options.empty()) return -1;

    std::vector<float> weights;
    weights.reserve(options.size());

    for (const auto& opt : options) {
        if (!opt->hasRoom()) {
            weights.push_back(0.0f);
            continue;
        }

        float w = p.getPreference(opt->getType())
                * opt->baseAttractiveness()
                * opt->getWeatherMultiplier();
        weights.push_back(w);
    }

    bool allZero = true;
    for (float w : weights) if (w > 0) { allZero = false; break; }
    if (allZero) return -1;

    return static_cast<int>(RandomGenerator::getInstance().weightedChoice(weights));
}