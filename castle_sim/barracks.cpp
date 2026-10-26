#include "barracks.hpp"

#include <iostream>

Barracks::Barracks(const std::string& name, int capacity)
    : m_name(name)
    , m_capacity(capacity)
{
    std::cout << "[Barracks] Построена казарма: " << m_name
        << " (вместимость " << m_capacity << ")\n";
}

Barracks::~Barracks()
{
    std::cout << "[Barracks] Казарма " << m_name << " разрушена\n";
}

bool Barracks::Recruit(Resident* resident)
{
    if (resident == nullptr)
    {
        std::cout << "[Barracks] Ошибка: пустой указатель на жителя\n";
        return false;
    }
    if (static_cast<int>(m_soldiers.size()) >= m_capacity)
    {
        std::cout << "[Barracks] Отказ: казарма " << m_name
            << " переполнена (макс " << m_capacity << ")\n";
        return false;
    }
    m_soldiers.push_back(resident);
    std::cout << "[Barracks] " << resident->GetName()
        << " зачислен в " << m_name << "\n";
    return true;
}

void Barracks::ReportStatus() const
{
    std::cout << "=== Казарма " << m_name
        << " (" << m_soldiers.size() << "/" << m_capacity << ") ===\n";
    for (const auto* soldier : m_soldiers)
    {
        soldier->PrintStatus();
    }
}

int Barracks::GetSoldierCount() const
{
    return static_cast<int>(m_soldiers.size());
}

const std::string& Barracks::GetName() const { return m_name; }