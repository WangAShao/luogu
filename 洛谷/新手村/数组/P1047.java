import java.util.Scanner;

public class P1047 {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int L = sc.nextInt();
        int M = sc.nextInt();
        int[] pos = new int[L + 1];
        for (int i = 0; i < M; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();

            for (int j = start; j <= end; j++) {
                if (pos[j] == 0) {
                    pos[j] = 1;
                }
            }//end for
        }//end for

        int count = 0;
        for (int i = 0; i <= L; i++) {
            if (pos[i] == 0)    {
                count++;
            }
        }
        System.out.println(count);
        sc.close();
    }
}