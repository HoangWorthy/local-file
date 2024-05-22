import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        child c = new child();
        c.setIq(5);
        System.out.println(c.nhan());
        Academic a = new Academic();
        a.setIq(10);
        System.out.println();
    }
}
