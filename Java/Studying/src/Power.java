public class Power {
    private int strength;

    public Power() {
    }

    public void setStrength(int strength) {
        this.strength = strength;
    }

    public int getStrength() {
        return strength;
    }
    public boolean answer(int strength){
        return !(strength<this.strength);
    }
}
