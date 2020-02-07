import java.util.Scanner;

public class P1046 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] heights = new int[10];

        for (int i = 0; i < 10; i++) {
            heights[i] = sc.nextInt();
        }

        int maxHeight = sc.nextInt();
        final int desk = 30;
        int amount = 0;
        for (int i = 0; i < 10; i++) {
            if( maxHeight + desk >= heights[i]) {
                amount++;
            }
        }

        System.out.println(amount);
        sc.close();
    }
}