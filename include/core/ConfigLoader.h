#ifndef TRANSITTYCOON_CONFIGLOADER_H
#define TRANSITTYCOON_CONFIGLOADER_H

#pragma once

#include <string>
#include <unordered_map>

class ConfigLoader {
    std::unordered_map<std::string, std::string> values;

public:
    explicit ConfigLoader(const std::string& filename);

    int getInt(const std::string& key) const;
    float getFloat(const std::string& key) const;
    std::string getString(const std::string& key) const;
};

#endif