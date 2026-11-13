#include "Castle.hpp"
#include "Soldier.hpp"
#include "Peasant.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "===== 1. АБСТРАКТНЫЙ КЛАСС И НАСЛЕДНИКИ =====\n";
    // BaseResident b("Иван"); // ОШИБКА! Нельзя создать абстрактный класс
    auto soldier = std::make_shared<Soldier>("Иван", "Меч");
    auto peasant = std::make_shared<Peasant>("Петр");

    std::cout << "\nПрофессии:\n";
    std::cout << soldier->GetName() << ": " << soldier->GetProfession() << "\n";
    std::cout << peasant->GetName() << ": " << peasant->GetProfession() << "\n";

    std::cout << "\nСтатический счетчик жителей: " << BaseResident::GetTotalResidents() << "\n";

    std::cout << "\n===== 2. ВИРТУАЛЬНЫЙ ДЕСТРУКТОР =====\n";
    {
        std::cout << "-- Создаем через указатель на базу --\n";
        std::unique_ptr<BaseResident> ptr = std::make_unique<Soldier>("Генерал", "Копье");
    } // Здесь вызовется и деструктор Soldier, и деструктор BaseResident

    std::cout << "\n===== 3. КОПИРОВАНИЕ (ГЛУБОКОЕ) =====\n";
    {
        Soldier original("Клон", "Топор");
        Soldier copy = original; // Вызов конструктора копирования
        std::cout << "Оригинал: " << original.Describe() << "\n";
        std::cout << "Копия:    " << copy.Describe() << "\n";
    }

    std::cout << "\n===== 4. ПОЛИМОРФИЗМ (ВЫЗОВ ЧЕРЕЗ БАЗУ) =====\n";
    std::vector<std::shared_ptr<BaseResident>> residents = { soldier, peasant };
    for (const auto& r : residents)
    {
        r->Work(); // Вызовется своя версия для каждого!
        std::cout << r->Describe() << "\n";
    }

    std::cout << "\n===== 5. СТРОКИ (std::string) =====\n";
    std::string report = "Жители: " + soldier->GetName() + " и " + peasant->GetName();
    std::cout << "Конкатенация: " << report << "\n";
    std::cout << "Поиск 'Петр': " << (report.find("Петр") != std::string::npos ? "Найден" : "Не найден") << "\n";

    std::cout << "\n===== 6. ИСПОЛЬЗОВАНИЕ КАЗАРМЫ (АГРЕГАЦИЯ) =====\n";
    Castle castle("Каменный", 1000, "Главная казарма", 2);
    castle.GetBarracks().Recruit(soldier);
    castle.GetBarracks().Recruit(peasant);
    castle.GetBarracks().ReportStatus();

    std::cout << "\n===== КОНЕЦ ПРОГРАММЫ =====\n";
    return 0;
}