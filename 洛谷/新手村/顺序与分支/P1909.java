import java.util.Scanner;
import java.util.Arrays;

public class P1909 {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        int[][] a = new int[3][2];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        sc.close();


        int min = Integer.MAX_VALUE;
        for (int i = 0; i < 3; i++) {
            int amount;
            amount = n > (n / a[i][0]) * a[i][0] ? (n / a[i][0] + 1) : (n / a[i][0]);

            min = min > (amount * a[i][1]) ? (amount * a[i][1]) : min;
        }

        System.out.println(min);

    }
}