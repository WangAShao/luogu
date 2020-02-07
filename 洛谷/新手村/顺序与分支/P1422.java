import java.util.Scanner;

public class P1422{
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner (System.in);
        double ans = 0;

        int n = sc.nextInt();
        sc.close();
        if (n <= 150)

            ans += n * 0.4463;

        else

        {

            n -= 150;

            ans += 150 * 0.4463;

            if (n <= 250)

                ans += n * 0.4663;

            else

            {

                n -= 250;

                ans += 250 * 0.4663;

                ans += n * 0.5663;

            }

        }

        System.out.printf("%.1f", ans);

    }
}