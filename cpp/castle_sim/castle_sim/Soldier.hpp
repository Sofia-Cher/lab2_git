#pragma once
#pragma once
#include "BaseResident.hpp"

class Soldier : public BaseResident
{
private:
    std::string m_weapon;

public:
    Soldier(const std::string& name, const std::string& weapon);
    ~Soldier() override; // override проверяет, что мы действительно переопределяем виртуальный метод

    std::string GetProfession() const override;
    void Work() override;
    std::string Describe() const override; // Переопределяем с вызовом базы
};