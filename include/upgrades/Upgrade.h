#ifndef TRANSITTYCOON_UPGRADE_H
#define TRANSITTYCOON_UPGRADE_H

#pragma once

#include <string>
#include <ostream>

class Game;

class Upgrade {
protected:
    std::string name;
    int price;

public:
    Upgrade(std::string name, int price);
    virtual ~Upgrade() = default;

    const std::string& getName() const { return name; }
    int getPrice() const { return price; }

    virtual void apply(Game& game) = 0;

    virtual std::string describe() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Upgrade& u);
};

#endif