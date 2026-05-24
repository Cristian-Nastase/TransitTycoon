#include "upgrades/UpgradeFactory.h"
#include "upgrades/UmbrellaUpgrade.h"
#include "upgrades/CapacityUpgrade.h"
#include "upgrades/HappinessUpgrade.h"
#include "upgrades/DiscountUpgrade.h"
#include "exceptions/GameExceptions.h"

#include <fstream>
#include <sstream>

std::unique_ptr<Upgrade> UpgradeFactory::create(const std::string& type,
                                                  const std::string& name,
                                                  int price,
                                                  float param) {
    if (type == "umbrella") {
        return std::make_unique<UmbrellaUpgrade>(name, price, param);
    }
    if (type == "capacity_metro") {
        return std::make_unique<CapacityUpgrade>(name, price,
                                                  TransportType::Metro,
                                                  static_cast<int>(param));
    }
    if (type == "capacity_tram") {
        return std::make_unique<CapacityUpgrade>(name, price,
                                                  TransportType::Tram,
                                                  static_cast<int>(param));
    }
    if (type == "capacity_bus") {
        return std::make_unique<CapacityUpgrade>(name, price,
                                                  TransportType::Bus,
                                                  static_cast<int>(param));
    }
    if (type == "happiness") {
        return std::make_unique<HappinessUpgrade>(name, price,
                                                   static_cast<int>(param));
    }
    if (type == "discount") {
        return std::make_unique<DiscountUpgrade>(name, price, param);
    }
    throw InvalidUpgradeException("Tip necunoscut: " + type);
}

Repository<std::unique_ptr<Upgrade>> UpgradeFactory::loadFromFile(
    const std::string& filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw ConfigException("Nu pot deschide " + filename);
    }

    Repository<std::unique_ptr<Upgrade>> repo;
    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        ++lineNum;
        if (line.empty() || line[0] == '#') continue;

        // format: type|name|price|param
        std::istringstream iss(line);
        std::string type, name, priceStr, paramStr;

        if (!std::getline(iss, type, '|') ||
            !std::getline(iss, name, '|') ||
            !std::getline(iss, priceStr, '|') ||
            !std::getline(iss, paramStr)) {
            throw ConfigException("Linie invalida " + std::to_string(lineNum)
                                   + " in " + filename);
        }

        try {
            int price = std::stoi(priceStr);
            float param = std::stof(paramStr);
            repo.add(create(type, name, price, param));
        } catch (const std::exception& e) {
            throw ConfigException("Eroare parsare linia "
                                   + std::to_string(lineNum) + ": " + e.what());
        }
    }

    return repo;
}