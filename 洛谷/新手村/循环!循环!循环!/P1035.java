import java.util.Scanner;

public class P1035 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        sc.close();

        int n = 1;
        double s = 0;
        while (s <= k) {
            s += 1.0 / n;
            //System.out.println(s);
            n++;
        }

        System.out.println(n - 1);
    }
}