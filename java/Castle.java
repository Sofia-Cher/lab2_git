public class Castle {
    private final String name;
    private int gold;
    private final Barracks barracks; // Композиция

    public Castle(String name, int gold, String barracksName, int barracksCapacity) {
        this.name = name;
        this.gold = gold;
        this.barracks = new Barracks(barracksName, barracksCapacity);
        System.out.println("[Castle] Основан замок: " + name + " (золото: " + gold + ")");
    }

    public void collectTaxes(int amount) {
        if (amount < 0) {
            System.out.println("[Castle] Ошибка: налог не может быть отрицательным");
            return;
        }
        gold += amount;
        System.out.println("[Castle] Собраны налоги: +" + amount + " (итого " + gold + ")");
    }

    public boolean spendGold(int amount) {
        if (amount < 0) {
            System.out.println("[Castle] Ошибка: сумма не может быть отрицательной");
            return false;
        }
        if (amount > gold) {
            System.out.println("[Castle] Отказ: не хватает золота (нужно " + amount + ", есть " + gold + ")");
            return false;
        }
        gold -= amount;
        System.out.println("[Castle] Потрачено: -" + amount + " (осталось " + gold + ")");
        return true;
    }

    public Barracks getBarracks() { return barracks; }

    @Override
    public String toString() {
        return "Замок " + name + " | Золото: " + gold + " | Бойцов: " + barracks.getSoldierCount();
    }
}