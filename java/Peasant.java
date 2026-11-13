public final class Peasant extends BaseResident { // final запрещает наследование

    public Peasant(String name) {
        super(name); // Вызов конструктора базы
        System.out.println("[Peasant] Крестьянин " + name + " готов к работе.");
    }

    @Override
    public String getProfession() { return "Крестьянин"; }

    @Override
    public void work() {
        System.out.println(getName() + " пашет землю.");
    }
    
    // Здесь мы НЕ переопределяем describe(), чтобы показать разницу (используется базовый)
}