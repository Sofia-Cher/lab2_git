public abstract class BaseResident {
    private static int totalResidents = 0; // Статический счетчик
    private final String name;
    private int health;
    protected int satiety; // protected: доступно наследникам

    public BaseResident(String name) {
        this.name = name;
        this.health = 100;
        this.satiety = 100;
        totalResidents++;
        System.out.println("[BaseResident] Создан житель: " + name);
    }

    // Конструктор копирования (для глубокой копии)
    public BaseResident(BaseResident other) {
        this.name = other.name + "_copy";
        this.health = other.health;
        this.satiety = other.satiety;
        totalResidents++;
        System.out.println("[BaseResident] Создана КОПИЯ жителя: " + this.name);
    }

    // Абстрактные методы (не имеют тела)
    public abstract String getProfession();
    public abstract void work();

    // Виртуальный метод с реализацией
    public String describe() {
        return "Житель " + name + " (Здоровье: " + health + ")";
    }

    public static int getTotalResidents() {
        return totalResidents;
    }

    public String getName() { return name; }
    public int getHealth() { return health; }
    public int getSatiety() { return satiety; }

    public void takeDamage(int damage) {
        if (damage < 0 || health <= 0) return;
        health -= damage;
        if (health < 0) health = 0;
    }

    public void eat(int food) {
        if (food < 0) return;
        satiety += food;
        if (satiety > 100) satiety = 100;
    }
}