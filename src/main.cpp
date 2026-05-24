#include "core/Game.h"
#include "ui/ConsoleUI.h"
#include "exceptions/GameExceptions.h"
#include "templates/Repository.h"

#include <iostream>

void demonstrateTemplates() {
    // Demonstrăm template-ul cu tipuri diferite (cerință explicită)
    std::cout << "\n--- Demonstratie template Repository ---\n";

    Repository<int> nums;
    nums.add(10);
    nums.add(20);
    nums.add(30);
    printRepository(nums, "Numere");

    Repository<std::string> words;
    words.add("hello");
    words.add("world");
    printRepository(words, "Cuvinte");

    auto evens = countMatching(nums, [](int n) { return n % 2 == 0; });
    std::cout << "Pare in lista numere: " << evens << "\n\n";
}

int main() {
    try {
        demonstrateTemplates();

        Game game("data/config.txt", "data/upgrades.txt");
        ConsoleUI ui(game);
        ui.run();

    } catch (const std::exception& e) {
        std::cerr << "[Eroare fatala] " << e.what() << "\n";
        return 1;
    }
    return 0;
}