import java.util.Scanner;

public class P1036 {
    static int k;
    static int n;
    static long ans;
    static int[] a;
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);

        n = sc.nextInt();
        k = sc.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        dfs(0, 0, 0);
        System.out.println(ans);
        sc.close();
    }

    private static void dfs(int m, int sum, int startx) {
        if(m == k){
            if (isPrime(sum)){
                ans++;
            }
            return ;
        }
        for (int i = startx; i < n ; i++) {
            dfs(m+1, sum + a[i], i + 1);
        }
        return;
    }

    private static boolean isPrime(int k) {
        if (k == 1) 
            return false;
        else if (k == 2)
            return true;
        else {
            for (int i = 2; i * i <= k; i++){
                if (k % i == 0) return false;
            }
            return true;
        }
    }
}