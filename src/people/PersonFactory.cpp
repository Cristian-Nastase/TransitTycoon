#include "../include/people/PersonFactory.h"
#include "../include/patterns/WeightedRandomStrategy.h"
#include "../include/patterns/CheapestStrategy.h"
#include "../include/core/RandomGenerator.h"

std::shared_ptr<Person> PersonFactory::createStudent(int id) {
    std::map<TransportType, float> prefs = {
        {TransportType::Metro,   0.8f},
        {TransportType::Tram,    0.6f},
        {TransportType::Bus,     0.5f},
        {TransportType::Walking, 0.9f}
    };
    return std::make_shared<Person>(
        "Student#" + std::to_string(id),
        std::move(prefs),
        90,
        70,
        std::make_unique<CheapestStrategy>()
    );
}

std::shared_ptr<Person> PersonFactory::createBusinessPerson(int id) {
    std::map<TransportType, float> prefs = {
        {TransportType::Metro,   0.9f},
        {TransportType::Tram,    0.4f},
        {TransportType::Bus,     0.3f},
        {TransportType::Walking, 0.1f}
    };
    return std::make_shared<Person>(
        "Business#" + std::to_string(id),
        std::move(prefs),
        20,
        60,
        std::make_unique<WeightedRandomStrategy>()
    );
}

std::shared_ptr<Person> PersonFactory::createTourist(int id) {
    std::map<TransportType, float> prefs = {
        {TransportType::Metro,   0.4f},
        {TransportType::Tram,    0.7f},
        {TransportType::Bus,     0.5f},
        {TransportType::Walking, 0.8f}
    };
    return std::make_shared<Person>(
        "Turist#" + std::to_string(id),
        std::move(prefs),
        100,
        80,
        std::make_unique<WeightedRandomStrategy>()
    );
}

std::shared_ptr<Person> PersonFactory::createElderly(int id) {
    std::map<TransportType, float> prefs = {
        {TransportType::Metro,   0.2f},
        {TransportType::Tram,    0.8f},
        {TransportType::Bus,     0.7f},
        {TransportType::Walking, 0.5f}
    };
    return std::make_shared<Person>(
        "Pensionar#" + std::to_string(id),
        std::move(prefs),
        50,
        30,
        std::make_unique<CheapestStrategy>()
    );
}

std::shared_ptr<Person> PersonFactory::createWorker(int id) {
    std::map<TransportType, float> prefs = {
        {TransportType::Metro,   0.5f},
        {TransportType::Tram,    0.7f},
        {TransportType::Bus,     0.8f},
        {TransportType::Walking, 0.3f}
    };
    return std::make_shared<Person>(
        "Muncitor#" + std::to_string(id),
        std::move(prefs),
        50,
        50,
        std::make_unique<WeightedRandomStrategy>()
    );
}

std::shared_ptr<Person> PersonFactory::createAthlete(int id) {
    std::map<TransportType, float> prefs = {
        {TransportType::Metro,   0.2f},
        {TransportType::Tram,    0.3f},
        {TransportType::Bus,     0.2f},
        {TransportType::Walking, 0.95f}
    };
    return std::make_shared<Person>(
        "Sportiv#" + std::to_string(id),
        std::move(prefs),
        80,
        90,
        std::make_unique<WeightedRandomStrategy>()
    );
}

std::shared_ptr<Person> PersonFactory::createRandom(int id) {
    auto& rng = RandomGenerator::getInstance();
    int type = rng.intInRange(0, 5);
    switch (type) {
        case 0: return createStudent(id);
        case 1: return createBusinessPerson(id);
        case 2: return createTourist(id);
        case 3: return createElderly(id);
        case 4: return createWorker(id);
        case 5: return createAthlete(id);
    }
    return createStudent(id);
}