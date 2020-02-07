import java.util.Scanner;

public class P1427 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] number = new int[100];
        int a;
        int i = 0;
        while((a = sc.nextInt()) != 0) {
            number[i++] = a;
        }

        for (int j = i - 1; j > 0; j--) {
            System.out.printf("%d ", number[j]);
        }
        System.out.print(number[0]);
        sc.close();
    }
}