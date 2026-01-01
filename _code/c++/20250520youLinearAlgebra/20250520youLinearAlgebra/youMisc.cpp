#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

namespace youMisc {
    // spilt function
    std::vector<std::string> split(const std::string& s, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(s);
        std::string item;

        while (std::getline(ss, item, delimiter)) {
            tokens.push_back(item);
        }

        return tokens;
    }
};