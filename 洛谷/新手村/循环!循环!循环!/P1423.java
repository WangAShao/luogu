import java.util.Scanner;

public class P1423 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();

        double pre = 2;
        double amount = 2;
        int n = 1;
        while(amount < x) {
            pre *= 0.98 ;
            amount += pre;
            n++;
        }

        System.out.println(n);
        sc.close();
    } 
}