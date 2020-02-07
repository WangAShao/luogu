import java.util.Scanner;

/**
 * P1031 这个题目的思路真心巧妙, 先把第一堆排好, 第一堆排好了之后其实就可以不用管第一堆了, 这个时候第二堆就又成了第一堆
 */
public class P1031 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int all = 0;
        int avg;
        int count = 0;

        int[] numsOfHeap = new int[n + 1];
        
        for (int i = 1; i <= n; i++) {
            numsOfHeap[i] = sc.nextInt();
            all += numsOfHeap[i];
        }
        sc.close();

        avg = all / n;

        for (int i = 1; i < n; i++) {
            if (numsOfHeap[i] != avg) {
                numsOfHeap[i + 1] += numsOfHeap[i] - avg;
                count++;
            }
        }

        System.out.println(count);
    }
}