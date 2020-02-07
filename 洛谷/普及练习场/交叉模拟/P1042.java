import java.util.Scanner;

/**
 * P1042
 */
public class P1042 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int score1 = 0;
        int score2 = 0;

        StringBuilder s = new StringBuilder();

        do {
            s.append(sc.next());
        } while (s.indexOf("E") == -1);

        sc.close();
        //记录胜负
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'W') {
                score1++;
            } else if (s.charAt(i) == 'L') {
                score2++;
            } else if (s.charAt(i) == 'E') {
                System.out.printf("%d:%d\n", score1, score2);
                break;
            }

            if (score1 >= 11 || score2 >= 11) {
                if (Math.abs(score1 - score2) >= 2) {
                    System.out.printf("%d:%d\n", score1, score2);
                    score1 = 0;
                    score2 = 0;
                }
            }
        }

        System.out.println();

        score1 = 0; score2 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'W') {
                score1++;
            } else if (s.charAt(i) == 'L') {
                score2++;
            } else if (s.charAt(i) == 'E') {
                System.out.printf("%d:%d\n", score1, score2);
                break;
            }

            if (score1 >= 21 || score2 >= 21) {
                if (Math.abs(score1 - score2) >= 2) {
                    System.out.printf("%d:%d\n", score1, score2);
                    score1 = 0;
                    score2 = 0;
                }
            }
        }
    }
}