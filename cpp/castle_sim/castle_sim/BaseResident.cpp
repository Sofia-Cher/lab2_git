#include "BaseResident.hpp"

// Инициализация статического поля (обязательно вне класса)
int BaseResident::m_totalResidents = 0;

BaseResident::BaseResident(const std::string& name)
    : m_name(name)
    , m_health(100)
    , m_satiety(100)
{
    m_totalResidents++;
    std::cout << "[BaseResident] Создан житель: " << m_name << "\n";
}

BaseResident::BaseResident(const BaseResident& other)
    : m_name(other.m_name + "_copy") // Добавляем пометку для наглядности
    , m_health(other.m_health)
    , m_satiety(other.m_satiety)
{
    m_totalResidents++;
    std::cout << "[BaseResident] Создана КОПИЯ жителя: " << m_name << "\n";
}

BaseResident::~BaseResident()
{
    std::cout << "[BaseResident] Уничтожен житель: " << m_name << "\n";
}

std::string BaseResident::Describe() const
{
    return "Житель " + m_name + " (Здоровье: " + std::to_string(m_health) + ")";
}

int BaseResident::GetTotalResidents()
{
    return m_totalResidents;
}

void BaseResident::TakeDamage(int damage)
{
    if (damage < 0) return;
    if (m_health <= 0) return;
    m_health -= damage;
    if (m_health < 0) m_health = 0;
}

void BaseResident::Eat(int food)
{
    if (food < 0) return;
    m_satiety += food;
    if (m_satiety > 100) m_satiety = 100;
}

bool BaseResident::ConsumeFood(int foodPerTurn)
{
    if (foodPerTurn <= 0) return false;
    if (m_satiety >= foodPerTurn)
    {
        m_satiety -= foodPerTurn;
        return true;
    }
    m_satiety = 0;
    TakeDamage(10);
    return false;
}