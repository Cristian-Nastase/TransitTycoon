#ifndef TRANSITTYCOON_UPGRADESFACTORY_H
#define TRANSITTYCOON_UPGRADESFACTORY_H

#pragma once

#include "upgrades/Upgrade.h"
#include "templates/Repository.h"
#include <memory>
#include <string>

class UpgradeFactory {
public:
    static std::unique_ptr<Upgrade> create(const std::string& type,
                                            const std::string& name,
                                            int price,
                                            float param);

    static Repository<std::unique_ptr<Upgrade>> loadFromFile(const std::string& filename);
};

#endif