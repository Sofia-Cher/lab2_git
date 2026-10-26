#include "castle.hpp"

#include <iostream>

Castle::Castle(const std::string& name, int gold,
    const std::string& barracksName, int barracksCapacity)
    : m_name(name)
    , m_gold(gold)
    , m_barracks(barracksName, barracksCapacity)
{
    std::cout << "[Castle] Основан замок: " << m_name
        << " (золото: " << m_gold << ")\n";
}

Castle::~Castle()
{
    std::cout << "[Castle] Замок " << m_name << " пал...\n";
}

void Castle::CollectTaxes(int amount)
{
    if (amount < 0)
    {
        std::cout << "[Castle] Ошибка: налог не может быть отрицательным\n";
        return;
    }
    m_gold += amount;
    std::cout << "[Castle] Собраны налоги: +" << amount
        << " (итого " << m_gold << ")\n";
}

bool Castle::SpendGold(int amount)
{
    if (amount < 0)
    {
        std::cout << "[Castle] Ошибка: сумма не может быть отрицательной\n";
        return false;
    }
    if (amount > m_gold)
    {
        std::cout << "[Castle] Отказ: не хватает золота (нужно " << amount
            << ", есть " << m_gold << ")\n";
        return false;
    }
    m_gold -= amount;
    std::cout << "[Castle] Потрачено: -" << amount
        << " (осталось " << m_gold << ")\n";
    return true;
}

Barracks& Castle::GetBarracks()
{
    return m_barracks;
}

void Castle::PrintStatus() const
{
    std::cout << "Замок " << m_name
        << " | Золото: " << m_gold
        << " | Бойцов: " << m_barracks.GetSoldierCount() << "\n";
}