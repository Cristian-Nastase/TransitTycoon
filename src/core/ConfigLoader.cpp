#include "core/ConfigLoader.h"
#include "exceptions/GameExceptions.h"

#include <fstream>
#include <sstream>

ConfigLoader::ConfigLoader(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw ConfigException("Nu poate fi deschis fisierul: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        const auto eg = line.find('=');
        if (eg == std::string::npos) continue;

        std::string key = line.substr(0, eg);
        std::string val = line.substr(eg + 1);
        values[key] = val;
    }
}

int ConfigLoader::getInt(const std::string& key) const {
    auto it = values.find(key);
    if (it == values.end()) {
        throw ConfigException("Cheia lipseste din config: " + key);
    }
    try {
        return std::stoi(it->second);
    } catch (const std::exception&) {
        throw ConfigException("Valoare invalida pentru " + key);
    }
}

float ConfigLoader::getFloat(const std::string& key) const {
    auto it = values.find(key);
    if (it == values.end()) {
        throw ConfigException("Cheia lipseste din config: " + key);
    }
    try {
        return std::stof(it->second);
    } catch (const std::exception&) {
        throw ConfigException("Valoare invalida pentru " + key);
    }
}

std::string ConfigLoader::getString(const std::string& key) const {
    auto it = values.find(key);
    if (it == values.end()) {
        throw ConfigException("Cheia lipseste din config: " + key);
    }
    return it->second;
}