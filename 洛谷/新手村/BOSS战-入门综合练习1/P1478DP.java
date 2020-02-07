import java.util.Scanner;

/**
 * P1478DP
 */
public class P1478DP {

    static int[][] dp = new int[5001][1001];
    static int[] xs;
    static int[] ys;
    static int n, s, a, b;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        s = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();

        xs = new int[n + 1];
        ys = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            xs[i] = sc.nextInt();
            ys[i] = sc.nextInt();
        }

        //dp[i][j]表示空间大小为j的背包装前i个物品所能得到的最大总价值
        for (int i = 1; i<= n; i++) {
            for (int j = 0; j <= s; j++) {
                dp[i][j] = dp[i - 1][j];
                if (xs[i] <= a + b && j >= ys[i]) {
                    dp[i][j] = dp[i - 1][j - ys[i]] + 1 > dp[i][j] ? dp[i - 1][j - ys[i]] + 1 : dp[i][j];
                }
            }
        }

        System.out.println(dp[n][s]);
    }
}