#include "ui/ConsoleUI.h"
#include "exceptions/GameExceptions.h"
#include "templates/Repository.h"

#include <iostream>
#include <iomanip>
#include <limits>

ConsoleUI::ConsoleUI(Game& game) : game(game) {}

void ConsoleUI::printHeader() {
std::cout<<"    _____________"<<'\n';
std::cout<<"  _/_|[][][][][] | - -"<<'\n';
std::cout<<"( Transit Tycoon | - -"<<'\n';
std::cout<<" =--OO-------OO--=dwb"<<"\n\n";
}

void ConsoleUI::printStatus() {
    std::cout << "\n--- Runda " << game.getRound() + 1
              << " | Bani: " << game.getMoney()
              << " | Vreme: " << WeatherSystem::weatherName(game.getCurrentWeather())
              << " ---\n";
    std::cout << "Mijloace de transport:\n";
    for (const auto& t : game.getTransports()) {
        std::cout << "  " << t->getName()
                  << " | capacitate: " << t->getCapacity()
                  << " | pret bilet: " << t->getTicketPrice()
                  << " | multiplicator vreme: " << std::fixed
                  << std::setprecision(2) << t->getWeatherMultiplier()
                  << "\n";
    }
}

void ConsoleUI::printRoundResult(const RoundResult& r) {
    std::cout << "\n>>> " << r << "\n";
}

void ConsoleUI::printUpgradeMenu() {
    std::cout << "\n--- Magazin Upgrade-uri (bani: " << game.getMoney() << ") ---\n";
    std::cout << "  0. Sari peste runda asta\n";

    std::size_t i = 1;
    game.getUpgrades().forEach([&](const std::unique_ptr<Upgrade>& u) {
        std::cout << "  " << i << ". " << *u << "\n";
        ++i;
    });
}

void ConsoleUI::printHistory() {
    printRepository(game.getHistory(), "Istoric runde");
}

void ConsoleUI::printPassengers() {
    printRepository(game.getCurrentPassengers(), "Pasagerii rundei curente");
}

int ConsoleUI::readInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            return value;
        }
        std::cout << "Input invalid. Incearca din nou.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool ConsoleUI::handleUpgradeChoice() {
    printUpgradeMenu();
    int max = static_cast<int>(game.getUpgrades().size());
    int choice = readInt("Alegere (0-" + std::to_string(max) + "): ", 0, max);

    if (choice == 0) {
        std::cout << "Sari peste runda.\n";
        return true;
    }

    try {
        game.applyUpgrade(static_cast<std::size_t>(choice - 1));
        std::cout << "Upgrade aplicat cu succes!\n";
    } catch (const InsufficientFundsException& e) {
        std::cout << "[Eroare] " << e.what() << "\n";
    } catch (const InvalidChoiceException& e) {
        std::cout << "[Eroare] " << e.what() << "\n";
    }
    return true;
}

void ConsoleUI::run() {
    printHeader();
    std::cout << "Pragul minim de fericire este "
              << game.getMinHappiness() << "%. Sub el, ai pierdut.\n";

    while (true) {
        printStatus();

        try {
            RoundResult r = game.runRound();
            printRoundResult(r);
        } catch (const GameOverException& e) {
            std::cout << "\n" << e.what() << "\n";
            printHistory();
            std::cout << "\nGame over la runda " << game.getRound() << ".\n";
            return;
        } catch (const std::exception& e) {
            std::cout << "[Eroare neasteptata] " << e.what() << "\n";
            return;
        }

        std::cout << "\nMeniu:\n";
        std::cout << "  1. Magazin upgrade-uri\n";
        std::cout << "  2. Continua urmatoarea runda\n";
        std::cout << "  3. Vezi pasagerii\n";
        std::cout << "  4. Vezi istoric\n";
        std::cout << "  5. Iesire\n";
        int choice = readInt("Alegere: ", 1, 5);

        switch (choice) {
            case 1: handleUpgradeChoice(); break;
            case 2: break;
            case 3: printPassengers(); break;
            case 4: printHistory(); break;
            case 5:
                std::cout << "La revedere!\n";
                return;
        }
    }
}