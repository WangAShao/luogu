import java.util.Scanner;

public class P1428 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] cuteValues = new int[n];
        int[] amount = new int[n];
        for (int i = 0; i < n; i++) {
            cuteValues[i] = sc.nextInt();
        }

        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (cuteValues[i] > cuteValues[j]) {
                    amount[i]++;
                }
            }
        }//end for

        for (int i = 0; i < n - 1; i++) {
            System.out.printf("%d ", amount[i]);
        }

        System.out.print(amount[n - 1]);
        sc.close();
    }
}