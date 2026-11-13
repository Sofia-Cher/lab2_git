#pragma once

#include "resident.hpp"

#include <string>
#include <vector>

class Barracks
{
private:
    std::string m_name;
    int m_capacity;
    std::vector<Resident*> m_soldiers;

public:
    Barracks(const std::string& name, int capacity);
    ~Barracks();

    bool Recruit(Resident* resident);
    void ReportStatus() const;
    int GetSoldierCount() const;
    const std::string& GetName() const;
};