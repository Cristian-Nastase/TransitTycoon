#ifndef TRANSITTYCOON_CONSOLEUI_H
#define TRANSITTYCOON_CONSOLEUI_H

#pragma once

#include "core/Game.h"
#include "core/WeatherSystem.h"

class ConsoleUI {
    Game& game;

    void printHeader();
    void printStatus();
    void printRoundResult(const RoundResult& r);
    void printUpgradeMenu();
    void printHistory();
    void printPassengers();
    bool handleUpgradeChoice();
    int readInt(const std::string& prompt, int min, int max);

public:
    explicit ConsoleUI(Game& game);
    void run();
};

#endif