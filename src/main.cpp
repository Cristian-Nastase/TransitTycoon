#include <iostream>
#include "../include/exceptions/GameExceptions.h"
#include "../include/core/RandomGenerator.h"
#include "../include/core/ConfigLoader.h"
#include "../include/core/WeatherSystem.h"
#include "../include/patterns/IObserver.h"
#include "../include/patterns/ISubject.h"

int main() {
    WeatherSystem we(0.6);
    auto i = 100;
    while (i) {
        std::cout<<WeatherSystem::weatherName(we.getCurrent())<<"\n";
        we.advance();
        i--;
    }
    std::cout << "Transport Tycoon - start\n";
    return 0;
}