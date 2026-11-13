#pragma once

#include "BaseResident.hpp"
#include <string>
#include <vector>
#include <memory>

class Barracks
{
private:
    std::string m_name;
    int m_capacity;

    // Агрегация: храним слабые указатели на базовый класс
    std::vector<std::weak_ptr<BaseResident>> m_soldiers;

public:
    Barracks(const std::string& name, int capacity);
    ~Barracks();

    // Принимаем shared_ptr на базовый класс
    bool Recruit(const std::shared_ptr<BaseResident>& resident);

    void ReportStatus() const;
    int GetSoldierCount() const;
    const std::string& GetName() const;
};