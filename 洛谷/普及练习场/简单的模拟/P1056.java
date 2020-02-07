import java.util.Scanner;

/**
 * P1056
 */
public class P1056 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();
        int l = sc.nextInt();
        int d = sc.nextInt();

        int[] xs = new int[1001];
        int[] ys = new int[1001];
        int[] r = new int[1001];
        int[] c = new int[1001];

        for (int i = 0; i < d; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int p = sc.nextInt();
            int q = sc.nextInt();

            if (x == p) { 
                xs[y < q ? y : q]++;
            } else {
                ys[x < p ? x : p]++;
            }
        }

        //给对应的桶中装元素
        for (int i = 1; i <= l; i++) {
            int maxn = -1;
            int index = -1;
            for (int j = 1; j < n; j++) {
                if (maxn < xs[j]) {
                    maxn = xs[j];
                    index = j;
                }
            }
            c[index]++;
            xs[index] = 0;
        }

        for (int i = 1; i <= k; i++) {
            int maxn = -1;
            int index = -1;
            for (int j = 1; j < m; j++) {
                if (maxn < ys[j]) {
                    maxn = ys[j];
                    index = j;
                } 
            }

            r[index]++;
            ys[index] = 0;
        }

        for (int i = 1; i < 1001; i++){
            if (r[i] != 0) System.out.printf("%d ", i);
        }
        System.out.println();
        for (int i = 1; i < 1001; i++) {
            if (c[i] != 0) System.out.printf("%d ", i);
        }
        System.out.println();

        sc.close();
    }
}