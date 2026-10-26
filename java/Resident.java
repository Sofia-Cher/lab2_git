public class Resident {
    public enum Profession {
        PEASANT, SOLDIER, BLACKSMITH
    }

    private final String name;
    private int health;
    private int satiety;
    private final Profession profession;

    public Resident(String name, Profession profession) {
        this.name = name;
        this.health = 100;
        this.satiety = 100;
        this.profession = profession;
        System.out.println("[Resident] Создан житель: " + name);
    }

    public Resident() {
        this("Безымянный", Profession.PEASANT);
    }

    public void takeDamage(int damage) {
        if (damage < 0) {
            System.out.println("[Resident] Ошибка: урон не может быть отрицательным");
            return;
        }
        if (health <= 0) {
            System.out.println("[Resident] " + name + " уже мёртв");
            return;
        }
        health -= damage;
        if (health < 0) {
            health = 0;
            System.out.println("[Resident] " + name + " погиб!");
        }
    }

    public void eat(int food) {
        if (food < 0) {
            System.out.println("[Resident] Ошибка: еда не может быть отрицательной");
            return;
        }
        satiety += food;
        if (satiety > 100) {
            satiety = 100;
            System.out.println("[Resident] " + name + " сыт полностью");
        }
    }

    public boolean consumeFood(int foodPerTurn) {
        if (foodPerTurn <= 0) {
            System.out.println("[Resident] Ошибка: еда за ход должна быть положительной");
            return false;
        }
        if (satiety >= foodPerTurn) {
            satiety -= foodPerTurn;
            return true;
        }
        satiety = 0;
        takeDamage(10);
        System.out.println("[Resident] " + name + " голодает!");
        return false;
    }

    public String getName() { return name; }
    public int getHealth() { return health; }
    public int getSatiety() { return satiety; }

    @Override
    public String toString() {
        return "Житель " + name + " | Здоровье: " + health + " | Сытость: " + satiety;
    }
}