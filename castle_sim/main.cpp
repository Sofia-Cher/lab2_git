#include "castle.hpp"
#include "resident.hpp"
#include <windows.h>
#include <iostream>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::cout << "===== СТАТИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ =====\n";
    Resident soldier1("Иван", Resident::Profession::eSoldier);
    Resident soldier2("Пётр", Resident::Profession::eSoldier);

    {
        std::cout << "\n===== СОЗДАНИЕ ЗАМКА (КОМПОЗИЦИЯ) =====\n";
        Castle castle("Каменный", 1000, "Главная казарма", 2);

        castle.GetBarracks().Recruit(&soldier1);
        castle.GetBarracks().Recruit(&soldier2);

        // Проверка правила: пытаемся набрать третьего — отказ
        Resident soldier3("Третий", Resident::Profession::eSoldier);
        castle.GetBarracks().Recruit(&soldier3);

        // Проверка правила: тратим больше, чем есть
        castle.SpendGold(5000);

        castle.PrintStatus();
        castle.GetBarracks().ReportStatus();

        std::cout << "\n===== ВЫХОД ИЗ БЛОКА: ЗАМОК И КАЗАРМА УМИРАЮТ =====\n";
    }

    std::cout << "\n===== ПОСЛЕ УНИЧТОЖЕНИЯ ЗАМКА =====\n";
    std::cout << "Проверяем, что жители живы:\n";
    soldier1.PrintStatus();
    soldier2.PrintStatus();

    // Демонстрация ConsumeFood
    std::cout << "\n===== ПРОВЕРКА ГОЛОДА =====\n";
    soldier1.ConsumeFood(95);   // съест, сытость 5
    soldier1.ConsumeFood(50);   // не хватит — голод
    soldier1.PrintStatus();

    std::cout << "\n===== ДИНАМИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ =====\n";
    Resident* dynamicResident = new Resident("Динамик", Resident::Profession::eBlacksmith);
    dynamicResident->TakeDamage(30);
    dynamicResident->PrintStatus();
    delete dynamicResident;

    std::cout << "\n===== МАССИВЫ =====\n";
    Resident arr[2];
    Resident* ptrArr[2];
    ptrArr[0] = new Resident("Дин1", Resident::Profession::eSoldier);
    ptrArr[1] = new Resident("Дин2", Resident::Profession::eSoldier);

    for (auto* r : ptrArr)
    {
        delete r;
    }

    std::cout << "\n===== КОНЕЦ ПРОГРАММЫ =====\n";
    return 0;
}