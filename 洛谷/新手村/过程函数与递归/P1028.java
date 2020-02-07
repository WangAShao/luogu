import java.util.Scanner;

public class P1028 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] a = new int[n + 1];
        if (n == 1) {
            a[1] = 1;
        } else if(n == 2){
            a[1] = 1; a[2] = 2;
        } else {
        a[1] = 1; a[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i/2; j++) {
                a[i] += a[j];
            }
            a[i]++;
        }
    }
        System.out.println(a[n]);
    }
}