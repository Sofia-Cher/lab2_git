public class Soldier extends BaseResident {
    private String weapon;

    public Soldier(String name, String weapon) {
        super(name); // Вызов конструктора базового класса
        this.weapon = weapon;
        System.out.println("[Soldier] Воин " + name + " вооружен: " + weapon);
    }

    // Конструктор копирования (глубокая копия)
    public Soldier(Soldier other) {
        super(other); // Копируем базовую часть
        this.weapon = new String(other.weapon); // Глубокая копия строки (создаем новый объект)
        System.out.println("[Soldier] Воин " + getName() + " вооружен: " + weapon);
    }

    @Override
    public String getProfession() { return "Воин"; }

    @Override
    public void work() {
        System.out.println(getName() + " тренируется с " + weapon + ".");
    }

    @Override
    public String describe() {
        // Вызов метода базового класса через super
        return super.describe() + " | Профессия: " + getProfession() + ", Оружие: " + weapon;
    }

    // Переопределяем equals для сравнения по содержимому (например, по имени и оружию)
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Soldier)) return false;
        Soldier soldier = (Soldier) o;
        return getName().equals(soldier.getName()) && weapon.equals(soldier.weapon);
    }

    @Override
    public int hashCode() {
        return getName().hashCode() + weapon.hashCode();
    }
}