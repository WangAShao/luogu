import java.util.Scanner;

/**
 * P1464
 */
public class P1464 {

    public static long dp[][][] = new long[50][50][50];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long c = sc.nextLong();

            if (a == -1 && b == -1 && c == -1) {
                break;
            }
            else {
				System.out.println("w("+a+", "+b+", "+c+") = "+w(a, b, c));			
			}
        }
    }

    private static long w (long a, long b, long c) {
        if (a <= 0 || b <= 0 || c <= 0) return 1;
        else if (a > 20 || b > 20 || c > 20) return w(20,20,20);
        else if (dp[(int)a][(int)b][(int)c] != 0) {
            return dp[(int)a][(int)b][(int)c];
        } else if(a < b && b < c) {
            dp[(int)a][(int)b][(int)c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        } else {
            dp[(int)a][(int)b][(int)c] =  w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a- 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        }
        return dp[(int)a][(int)b][(int)c];
    }
}