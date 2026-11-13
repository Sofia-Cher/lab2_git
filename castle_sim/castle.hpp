#pragma once

#include "barracks.hpp"

#include <string>

class Castle
{
private:
    std::string m_name;
    int m_gold;
    Barracks m_barracks;

public:
    Castle(const std::string& name, int gold,
        const std::string& barracksName, int barracksCapacity);
    ~Castle();

    void CollectTaxes(int amount);
    bool SpendGold(int amount);
    Barracks& GetBarracks();
    void PrintStatus() const;
};