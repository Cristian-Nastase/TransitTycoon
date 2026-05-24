#include <iostream>
#include "exceptions/GameExceptions.h"
#include "core/RandomGenerator.h"
#include "core/ConfigLoader.h"
#include "core/WeatherSystem.h"
#include "patterns/IObserver.h"
#include "patterns/ISubject.h"
#include "people/PersonFactory.h"

int main() {
    std::vector<std::shared_ptr<Person>> people;
    people.reserve(100);

    for (int i = 0; i < 100; ++i) {
        people.push_back(PersonFactory::createRandom(i));
        std::cout<<*people[i]<<'\n';
    }

    std::cout << "Transport Tycoon - start\n";
    return 0;
}