import java.util.Scanner;

public class P1149 {
    static int[] number = {6,2,5,5,4,5,6,3,7,6};
    static int n;
    static int count;

    /**
     * this function is to calculate the amount of the match stick of the number needed
     * @param num
     * @return the number of match sticks
     */
    private static int calNum(int num) {
        int sum = 0;
        if (num == 0) return 6;
        while (num / 10 != 0 || num % 10 != 0) {
            sum += number[num % 10];
            num /= 10;
        }
        return sum;
    }

    private static void dfs(int k, int amount, int sum) {
        if (k == 2) {
            // it is the symbol of the third time
            if (amount + calNum(sum) == n) {
                count++;
               
            } 
            return;
        }
        for (int i = 0; i < 999; i++) {
            dfs(k + 1, amount + calNum(i), sum + i);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        dfs(0, 4, 0);
        System.out.println(count);
        sc.close();
    }
}