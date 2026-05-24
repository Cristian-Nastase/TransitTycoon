#include <iostream>
#include "../include/exceptions/GameExceptions.h"
#include "../include/core/RandomGenerator.h"

int main() {
    try {
        throw InsufficientFundsException(499, 200);
    }
    catch (GameException& e) {
        cout<<e.what()<<'\n';
    }
    std::cout << "Transport Tycoon - start\n";
    return 0;
}