public class Main {
    public static void main(String[] args) {
        System.out.println("===== 1. АБСТРАКТНЫЙ КЛАСС И НАСЛЕДНИКИ =====");
        // BaseResident b = new BaseResident("Иван"); // ОШИБКА: нельзя создать абстрактный класс
        Soldier soldier = new Soldier("Иван", "Меч");
        Peasant peasant = new Peasant("Петр");

        System.out.println("\nПрофессии:");
        System.out.println(soldier.getName() + ": " + soldier.getProfession());
        System.out.println(peasant.getName() + ": " + peasant.getProfession());
        System.out.println("\nСтатический счетчик жителей: " + BaseResident.getTotalResidents());

        System.out.println("\n===== 2. КОПИРОВАНИЕ (ГЛУБОКОЕ) =====");
        Soldier original = new Soldier("Клон", "Топор");
        Soldier copy = new Soldier(original); // Вызов конструктора копирования
        
        System.out.println("Оригинал: " + original.describe());
        System.out.println("Копия:    " + copy.describe());
        
        // Проверка equals
        System.out.println("Оригинал равен копии? " + original.equals(copy)); // false, т.к. имена разные (Клон и Клон_copy)

        System.out.println("\n===== 3. ПОЛИМОРФИЗМ (ВЫЗОВ ЧЕРЕЗ БАЗУ) =====");
        BaseResident[] residents = { soldier, peasant };
        for (BaseResident r : residents) {
            r.work(); // У каждого своя реализация
            System.out.println(r.describe());
        }

        System.out.println("\n===== 4. СТРОКИ И this =====");
        String report = "Жители: " + soldier.getName() + " и " + peasant.getName();
        System.out.println("Конкатенация: " + report);
        System.out.println("Поиск 'Петр': " + (report.contains("Петр") ? "Найден" : "Не найден"));

        System.out.println("\n===== 5. ИСПОЛЬЗОВАНИЕ КАЗАРМЫ (АГРЕГАЦИЯ) =====");
        Castle castle = new Castle("Каменный", 1000, "Главная казарма", 2);
        castle.getBarracks().recruit(soldier);
        castle.getBarracks().recruit(peasant);
        castle.getBarracks().reportStatus();

        System.out.println("\n===== КОНЕЦ ПРОГРАММЫ =====");
    }
}