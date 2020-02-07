import java.util.Scanner;

import java.util.Arrays;

/**
 * P1618
 */
public class P1618 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        boolean flag = false;

        //预处理, 将其化为最简整数比
        int g1 = gcd(a, b);
        int g2 = gcd(g1, c);

        a = a / g2;
        b = b / g2;
        c = c / g2;

        //这里是为了保证所有的枚举的i都是可以被a整除的
        int start = 123 / a + 123 % a > 1 ? 1 : 123 % a;
        for (int i = start; i < 1000; i += a) {
            int j = b * i;
            int k = c * i;

            String str = "" + i + j + k;
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String sorted = String.valueOf(arr);

            if (sorted.equals("123456789")){
                flag = true;
                System.out.printf("%d %d %d\n", i, j, k);
            }             
        }

        if (!flag) {
            System.out.println("No!!!");
        }

        sc.close();
    }
    
    private static int gcd (int x, int y) {
        if(y == 0) 
            return x;
        else 
            return gcd(y, x % y);
    }

}