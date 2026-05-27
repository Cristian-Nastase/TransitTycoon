#include "core/Game.h"
#include "ui/ConsoleUI.h"
#include "exceptions/GameExceptions.h"
#include "templates/Repository.h"

#include <iostream>

int main() {
    try {
        Game game("../data/config.txt", "../data/upgrades.txt");
        ConsoleUI ui(game);
        ui.run();

    } catch (const std::exception& e) {
        std::cerr << "[Eroare fatala] " << e.what() << "\n";
        return 1;
    }
    return 0;
}