#include "Peasant.hpp"

Peasant::Peasant(const std::string& name)
    : BaseResident(name)
{
    std::cout << "[Peasant] Крестьянин " << name << " готов к работе.\n";
}

Peasant::~Peasant()
{
    std::cout << "[Peasant] Крестьянин уничтожен\n";
}

std::string Peasant::GetProfession() const { return "Крестьянин"; }

void Peasant::Work()
{
    std::cout << GetName() << " пашет землю.\n";
}