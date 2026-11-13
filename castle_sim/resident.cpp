#include "resident.hpp"

#include <iostream>

Resident::Resident(const std::string& name, Profession profession)
    : m_name(name)
    , m_health(100)
    , m_satiety(100)
    , m_profession(profession)
{
    std::cout << "[Resident] Создан житель: " << m_name << "\n";
}

Resident::Resident()
    : m_name("Безымянный")
    , m_health(100)
    , m_satiety(100)
    , m_profession(Profession::ePeasant)
{
    std::cout << "[Resident] Создан житель по умолчанию: " << m_name << "\n";
}

Resident::~Resident()
{
    std::cout << "[Resident] Уничтожен житель: " << m_name << "\n";
}

void Resident::TakeDamage(int damage)
{
    if (damage < 0)
    {
        std::cout << "[Resident] Ошибка: урон не может быть отрицательным\n";
        return;
    }

    // Защита: житель не может получить урон, если уже мёртв
    if (m_health <= 0)
    {
        std::cout << "[Resident] " << m_name << " уже мёртв\n";
        return;
    }

    m_health -= damage;
    if (m_health < 0)
    {
        m_health = 0;
        std::cout << "[Resident] " << m_name << " погиб!\n";
    }
}

void Resident::Eat(int food)
{
    if (food < 0)
    {
        std::cout << "[Resident] Ошибка: еда не может быть отрицательной\n";
        return;
    }
    m_satiety += food;
    if (m_satiety > 100)
    {
        m_satiety = 100;
        std::cout << "[Resident] " << m_name << " сыт полностью\n";
    }
}

bool Resident::ConsumeFood(int foodPerTurn)
{
    if (foodPerTurn <= 0)
    {
        std::cout << "[Resident] Ошибка: еда за ход должна быть положительной\n";
        return false;
    }

    if (m_satiety >= foodPerTurn)
    {
        m_satiety -= foodPerTurn;
        return true;
    }

    m_satiety = 0;
    TakeDamage(10);
    std::cout << "[Resident] " << m_name << " голодает!\n";
    return false;
}

void Resident::PrintStatus() const
{
    std::cout << "Житель " << m_name
        << " | Здоровье: " << m_health
        << " | Сытость: " << m_satiety << "\n";
}

const std::string& Resident::GetName() const { return m_name; }
int Resident::GetHealth() const { return m_health; }
int Resident::GetSatiety() const { return m_satiety; }
Resident::Profession Resident::GetProfession() const { return m_profession; }