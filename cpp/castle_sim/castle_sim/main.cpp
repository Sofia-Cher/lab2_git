#include "castle.hpp"
#include "resident.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "===== 1. UNIQUE_PTR (ЕДИНОЛИЧНОЕ ВЛАДЕНИЕ) =====\n";
    {
        // Создаем объект через make_unique (без new)
        std::unique_ptr<Resident> uniqueResident = std::make_unique<Resident>("Уникальный", Resident::Profession::eSoldier);
        uniqueResident->TakeDamage(10);

        std::cout << "Владельцев unique_ptr: 1 (копировать нельзя)\n";

        // Передача владения через std::move
        std::unique_ptr<Resident> movedResident = std::move(uniqueResident);

        if (!uniqueResident) {
            std::cout << "Владение передано! Исходный uniqueResident теперь пуст.\n";
        }
    } // Здесь сработает деструктор movedResident (delete вызовется автоматически)

    std::cout << "\n===== 2. SHARED_PTR (СОВМЕСТНОЕ ВЛАДЕНИЕ) =====\n";
    // Создаем Ивана (он будет жить долго)
    std::shared_ptr<Resident> sharedIvan = std::make_shared<Resident>("Иван", Resident::Profession::eSoldier);
    std::cout << "Владельцев Ивана: " << sharedIvan.use_count() << "\n"; // 1

    {
        // Создаем Петра (он умрет в конце этого блока)
        std::shared_ptr<Resident> sharedPetr = std::make_shared<Resident>("Пётр", Resident::Profession::eSoldier);
        std::cout << "Владельцев Петра: " << sharedPetr.use_count() << "\n"; // 1

        // Делаем копию указателя на Ивана
        std::shared_ptr<Resident> copyIvan = sharedIvan;
        std::cout << "Владельцев Ивана после копирования: " << sharedIvan.use_count() << "\n"; // 2
    } // Блок заканчивается. Уничтожаются sharedPetr и copyIvan.

    std::cout << "Владельцев Ивана после выхода из блока: " << sharedIvan.use_count() << "\n"; // 1

    std::cout << "\n===== 3. WEAK_PTR И АГРЕГАЦИЯ =====\n";
    Castle castle("Каменный", 1000, "Главная казарма", 2);

    // Передаем Ивана в казарму (казарма сохранит weak_ptr)
    castle.GetBarracks().Recruit(sharedIvan);

    {
        // Создаем Петра и сразу отдаем в казарму
        std::shared_ptr<Resident> sharedPetr = std::make_shared<Resident>("Пётр", Resident::Profession::eSoldier);
        castle.GetBarracks().Recruit(sharedPetr);

        castle.GetBarracks().ReportStatus();
        std::cout << "-> Выходим из блока. Пётр будет уничтожен, так как на него больше нет shared_ptr.\n";
    }

    std::cout << "\nПроверяем казарму после смерти Петра (weak_ptr Петра станет пустым):\n";
    castle.GetBarracks().ReportStatus();

    std::cout << "\n===== 4. УНИЧТОЖЕНИЕ ПОСЛЕДНЕГО ВЛАДЕЛЬЦА =====\n";
    sharedIvan.reset(); // Уничтожаем последнего владельца Ивана
    std::cout << "Иван уничтожен (счётчик shared_ptr стал 0).\n";

    std::cout << "\n===== КОНЕЦ ПРОГРАММЫ =====\n";
    return 0;
}