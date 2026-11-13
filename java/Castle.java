public class Castle {
    private final String name;
    private int gold;
    private final Barracks barracks; // Композиция

    public Castle(String name, int gold, String barracksName, int barracksCapacity) {
        this.name = name;
        this.gold = gold;
        this.barracks = new Barracks(barracksName, barracksCapacity); // Создаем сами
        System.out.println("[Castle] Основан замок: " + name + " (золото: " + gold + ")");
    }

    public Barracks getBarracks() { return barracks; }

    @Override
    public String toString() {
        return "Замок " + name + " | Золото: " + gold + " | Бойцов: " + barracks.getSoldierCount();
    }
}