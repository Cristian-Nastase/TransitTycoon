#ifndef TRANSITTYCOON_GAMEEXCEPTIONS_H
#define TRANSITTYCOON_GAMEEXCEPTIONS_H

#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class GameException : public runtime_error {
public:
    explicit GameException(const std::string& msg)
        : runtime_error(msg) {}
};

class GameOverException : public GameException {
public:
    explicit GameOverException(const string& msg)
        : GameException("[GAME OVER] " + msg) {}
};

class InsufficientFundsException : public GameException {
public:
    explicit InsufficientFundsException(int needed, int available)
        : GameException("Fonduri insuficiente: ai nevoie de " + to_string(needed) + ", ai doar " + to_string(available)) {}
};

class InvalidUpgradeException : public GameException {
public:
    explicit InvalidUpgradeException(const string& msg)
        : GameException("Upgrade invalid: " + msg) {}
};

class ConfigException : public GameException {
public:
    explicit ConfigException(const string& msg)
        : GameException("Eroare configurare: " + msg) {}
};

class InvalidChoiceException : public GameException {
public:
    explicit InvalidChoiceException(const string& msg)
        : GameException("Alegere invalida: " + msg) {}
};

#endif