import java.util.ArrayList;
import java.util.List;

public class Barracks {
    private final String name;
    private final int capacity;
    // Агрегация: храним ссылки на базовый класс
    private final List<BaseResident> soldiers;

    public Barracks(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.soldiers = new ArrayList<>();
        System.out.println("[Barracks] Построена казарма: " + name + " (вместимость " + capacity + ")");
    }

    public boolean recruit(BaseResident resident) {
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
        for (BaseResident soldier : soldiers) {
            System.out.println(soldier.describe()); // Полиморфизм!
        }
    }

    public int getSoldierCount() {
        return soldiers.size();
    }

    public String getName() { return name; }
}