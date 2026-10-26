#pragma once

#include <string>

class Resident
{
public:
    enum class Profession
    {
        ePeasant,
        eSoldier,
        eBlacksmith
    };

private:
    std::string m_name;
    int m_health;
    int m_satiety;
    Profession m_profession;

public:
    Resident(const std::string& name, Profession profession);
    Resident();
    ~Resident();

    void TakeDamage(int damage);
    void Eat(int food);
    bool ConsumeFood(int foodPerTurn);
    void PrintStatus() const;

    const std::string& GetName() const;
    int GetHealth() const;
    int GetSatiety() const;
    Profession GetProfession() const;
};