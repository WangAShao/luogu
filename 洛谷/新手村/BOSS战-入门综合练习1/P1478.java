import java.util.Scanner;
import java.util.Arrays;
/**
 * P1478
 */
public class P1478 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();//苹果数n
        int s = sc.nextInt();//力气s
        int a = sc.nextInt();//椅子的高度a
        int b = sc.nextInt();//伸直手的最大长度b

        int[] xs = new int[n];
        int[] ys = new int[n];

        int count = 0;

        int x, y;
        for (int i = 0; i < n; i++) {
            x = sc.nextInt();
            y = sc.nextInt();

            if (x <= b + a) {
                xs[count] = x;
                ys[count++] = y;
            }
        }
        Arrays.sort(ys);
        int counts = 0;
        for (int i = n - count; i < n; i++) {
            s -= ys[i];
            if (s >= 0)
                counts++;
            else {
                break;
            }
        }

        System.out.println(counts);
        sc.close();
    }
}