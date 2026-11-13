#pragma once
#pragma once
#include "BaseResident.hpp"

// Слово final запрещает кому-либо наследоваться от класса Peasant
class Peasant final : public BaseResident
{
public:
    Peasant(const std::string& name);
    ~Peasant() override;

    std::string GetProfession() const override;
    void Work() override;
    // Мы НЕ переопределяем Describe(), чтобы показать разницу
};