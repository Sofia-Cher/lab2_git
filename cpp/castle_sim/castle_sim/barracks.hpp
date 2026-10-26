#pragma once

#include "resident.hpp"
#include <string>
#include <vector>
#include <memory> 

class Barracks
{
private:
    std::string m_name;
    int m_capacity;


    std::vector<std::weak_ptr<Resident>> m_soldiers;

public:
    Barracks(const std::string& name, int capacity);
    ~Barracks();


    bool Recruit(const std::shared_ptr<Resident>& resident);

    void ReportStatus() const;
    int GetSoldierCount() const;
    const std::string& GetName() const;
};