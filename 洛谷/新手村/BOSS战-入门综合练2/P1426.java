import java.util.Scanner;

/**
 * P1426
 */
public class P1426 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double s = sc.nextInt();
        double x = sc.nextInt();

        double now = 0; double l = s - x; double r = s + x; double meter = 7;

        while (true) {
            if (now > r) {
                System.out.println("n");
                return ;
            }

            else if (l < now && now < r) {
                if (now + meter > r) {
                    System.out.println("n");
                    return;
                } else {
                    System.out.println("y");
                    return;
                }
            }
            now += meter;
            meter *= 0.98;
            
        }
    }
}