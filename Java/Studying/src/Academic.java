public class Academic {
    protected int iq;

    public Academic() {
    }

    public void setIq(int iq) {
        this.iq = iq;
    }

    public int getIq() {
        return iq;
    }
    public boolean answer(int iq){
        return !(iq < this.iq);
    }
    public int iq(){
        return this.iq*2;
    }
}
