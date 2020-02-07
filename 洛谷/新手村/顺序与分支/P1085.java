import java.util.Arrays;
import java.util.Scanner;

public class P1085{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[7];
        int max = 0;
        int day = 0;
        for (int i = 0; i < 7; i++) {
            a[i] = sc.nextInt() + sc.nextInt();
            if (a[i] >= 8) {
                if (a[i] > max) {
                    max = a[i];
                    day = i + 1;
                }
            }
        }
        System.out.println(day);
        sc.close();
    }
}