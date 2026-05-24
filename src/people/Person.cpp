#include "people/Person.h"

Person::Person(std::string name,
               std::map<TransportType, float> preferences,
               int mood,
               int budget,
               std::unique_ptr<ChoiceStrategy> strategy)
    : name(std::move(name)),
      preferences(std::move(preferences)),
      mood(mood),
      budget(budget),
      boost(0),
      strategy(std::move(strategy)) {}

float Person::getPreference(TransportType t) const {
    auto it = preferences.find(t);
    return (it != preferences.end()) ? it->second : 0.0f;
}

int Person::chooseTransport(
    const std::vector<std::shared_ptr<TransportMode>>& options) const {
    return strategy->choose(*this, options);
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << " (mood: " << p.getMood()
            << ", strategy: " << p.strategy->name() << ")";
    return os;
}
