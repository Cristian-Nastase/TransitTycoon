#include <iostream>
#include "../include/exceptions/GameExceptions.h"
#include "../include/core/RandomGenerator.h"
#include "../include/core/ConfigLoader.h"
#include "../include/core/WeatherSystem.h"
#include "../include/patterns/IObserver.h"
#include "../include/patterns/ISubject.h"
#include "../include/people/PersonFactory.h"

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