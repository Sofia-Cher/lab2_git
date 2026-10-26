import java.util.ArrayList;
import java.util.List;

public class Barracks {
    private final String name;
    private final int capacity;
    private final List<Resident> soldiers; // Агрегация

    public Barracks(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.soldiers = new ArrayList<>();
        System.out.println("[Barracks] Построена казарма: " + name + " (вместимость " + capacity + ")");
    }

    public boolean recruit(Resident resident) {
        if (resident == null) {
            System.out.println("[Barracks] Ошибка: пустая ссылка на жителя");
            return false;
        }
        if (soldiers.size() >= capacity) {
            System.out.println("[Barracks] Отказ: казарма " + name + " переполнена (макс " + capacity + ")");
            return false;
        }
        soldiers.add(resident);
        System.out.println("[Barracks] " + resident.getName() + " зачислен в " + name);
        return true;
    }

    public void reportStatus() {
        System.out.println("=== Казарма " + name + " (" + soldiers.size() + "/" + capacity + ") ===");
        for (Resident soldier : soldiers) {
            System.out.println(soldier.toString());
        }
    }

    public int getSoldierCount() {
        return soldiers.size();
    }

    public String getName() { return name; }
}