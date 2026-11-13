#pragma once

#include <string>
#include <iostream>

class BaseResident
{
private:
    std::string m_name;
    int m_health;
    static int m_totalResidents; // Статическое поле (счётчик всех жителей)

protected:
    // protected нужен, чтобы наследники могли это видеть, но снаружи (в main) менять нельзя
    int m_satiety;

public:
    BaseResident(const std::string& name);
    BaseResident(const BaseResident& other); // Конструктор копирования
    virtual ~BaseResident(); // Виртуальный деструктор!

    // Чисто виртуальные методы (делают класс абстрактным, у них нет тела)
    virtual std::string GetProfession() const = 0;
    virtual void Work() = 0;

    // Виртуальный метод (с реализацией, наследник может переопределить)
    virtual std::string Describe() const;

    // Статический метод
    static int GetTotalResidents();

    std::string GetName() const { return m_name; }
    int GetHealth() const { return m_health; }
    int GetSatiety() const { return m_satiety; }

    void TakeDamage(int damage);
    void Eat(int food);
    bool ConsumeFood(int foodPerTurn);
};