import java.lang.ref.WeakReference;

public class Main {
    public static void main(String[] args) {
        System.out.println("===== 1. ССЫЛКИ И КОПИИ =====");
        Resident first = new Resident("Иван", Resident.Profession.SOLDIER);
        Resident second = first; 
        second.takeDamage(30);
        System.out.println("Состояние first после изменения через second:");
        System.out.println(first.toString()); 

        System.out.println("\n===== 2. КОМПОЗИЦИЯ И АГРЕГАЦИЯ =====");
        Resident petr = new Resident("Пётр", Resident.Profession.SOLDIER);
        
        Castle castle = new Castle("Каменный", 1000, "Главная казарма", 2);
        castle.getBarracks().recruit(first);
        castle.getBarracks().recruit(petr);
        
        Resident third = new Resident("Третий", Resident.Profession.SOLDIER);
        castle.getBarracks().recruit(third);
        
        System.out.println(castle.toString());
        castle.getBarracks().reportStatus();

        System.out.println("\n===== 3. ОСВОБОЖДЕНИЕ РЕСУРСА (AutoCloseable) =====");
        try (IssueLog log = new IssueLog("Журнал замка")) {
            log.write("Зачислен Иван");
            log.write("Зачислен Пётр");
        } 

        System.out.println("\n===== 4. СБОРЩИК МУСОРА =====");
        Resident temp = new Resident("Временный", Resident.Profession.PEASANT);
        WeakReference<Resident> watcher = new WeakReference<>(temp);
        System.out.println("Объект жив? " + (watcher.get() != null));
        
        temp = null; 
        System.out.println("Ссылка обнулена. Выходим из блока...");
        
        System.gc(); 
        try { Thread.sleep(100); } catch (InterruptedException e) {} 
        
        System.out.println("После System.gc(): Объект жив? " + (watcher.get() != null));
        
        System.out.println("\n===== КОНЕЦ ПРОГРАММЫ =====");
    }
}