#include "Soldier.hpp"

Soldier::Soldier(const std::string& name, const std::string& weapon)
    : BaseResident(name) // ВЫЗОВ КОНСТРУКТОРА БАЗОВОГО КЛАССА (обязательно!)
    , m_weapon(weapon)
{
    std::cout << "[Soldier] Воин " << name << " вооружен: " << m_weapon << "\n";
}

Soldier::~Soldier()
{
    std::cout << "[Soldier] Воин уничтожен\n";
}

std::string Soldier::GetProfession() const { return "Воин"; }

void Soldier::Work()
{
    std::cout << GetName() << " тренируется с " << m_weapon << ".\n";
}

std::string Soldier::Describe() const
{
    // ВЫЗОВ МЕТОДА БАЗОВОГО КЛАССА
    return BaseResident::Describe() + " | Профессия: " + GetProfession() + ", Оружие: " + m_weapon;
}