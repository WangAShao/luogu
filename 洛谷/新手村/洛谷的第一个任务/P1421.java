import java.util.Scanner;

public class P1421 {
    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();
        int b = cin.nextInt();
        cin.close();

        int sum = a * 10 + b;
        int amount = sum / 19;
        System.out.println(amount);
    }
}