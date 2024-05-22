public class Business {
    private double price;
    private int quantity;

    public Business() {
    }


    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public double getQuantity() {
        return quantity;
    }
    public double totalPrice(){
        return price*quantity;
    }
    public boolean answer(int price) {
        return !(price < this.price);
    }
}
