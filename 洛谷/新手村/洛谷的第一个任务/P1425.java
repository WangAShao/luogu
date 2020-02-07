import java.util.Scanner;

public class P1425{
    public static void main(String[] args) throws Exception{
        Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();
        int b = cin.nextInt();
        int c = cin.nextInt();
        int d = cin.nextInt();
        cin.close();

        int x = c - a;
        int y = d - b;

        if (y < 0) {
            x--;
            y += 60;
        }

        System.out.printf("%d %d", x, y);
    }
}