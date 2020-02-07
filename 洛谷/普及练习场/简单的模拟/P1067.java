import java.util.Scanner;

/**
 * P1067
 */
public class P1067 {

    static boolean flag = false;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int next;
        for (int i = n; i >= 0; i--) {
            next = sc.nextInt();
            printItem(next, i, n);
        }
        if (flag == false) {
            System.out.print(0);
        }

        sc.close();
    }

    private static void printItem(int next, int i, int n) {
      if (next != 0) { 
        flag = true;  
        if (i != n && next > 0) {
            System.out.print("+");
        }

        if (Math.abs(next) > 1 || i == 0) {
            System.out.print(next);
        }

        if (next == -1 && (i != 0)) {
            System.out.print("-");
        }

        if (i > 1) {
            System.out.print("x^" + i);
        }

        if (i == 1) {
            System.out.print("x");
        }}
        
    }
}