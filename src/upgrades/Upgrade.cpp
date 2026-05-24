#include "upgrades/Upgrade.h"

Upgrade::Upgrade(std::string name, int price)
    : name(std::move(name)), price(price) {}

std::ostream& operator<<(std::ostream& os, const Upgrade& u) {
    os << u.name << " [" << u.price << " coins] - " << u.describe();
    return os;
}