import java.util.Scanner;

/**
 * P1177 这段代码的可扩展性更强, 但是消耗的内存也更大, 所以通过不了OJ
 */
public class P1177 {

    static Scanner sc = new Scanner(System.in);
    static int n;
    public static void sort(Comparable[] a) {
        sort(a, 0, a.length - 1);
    }

    private static void sort(Comparable[] a, int lo, int hi) {
        if (hi <= lo) return;
        int j = partition(a, lo, hi); //切分
        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
    }

    private static int partition(Comparable[] a, int lo, int hi) {
        int i = lo, j = hi + 1;
        Comparable v = a[lo]; //选择这个元素作为切分元素
        while(true) {
            while(a[++i].compareTo(v) < 0) {if (i == hi) break;} 
            while(a[--j].compareTo(v) > 0) {if (j == lo) break;}
            if (i >= j) break;
            exch(a, i, j); 
        }
        exch(a, lo, j);
        return j;
    }

    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    public static void main(String[] args) {
        n = sc.nextInt();
        Comparable[] a = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sort(a);
        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", a[i]);
        }
    }
}