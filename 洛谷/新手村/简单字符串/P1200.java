import java.util.Scanner;

public class P1200{
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        String comet = sc.nextLine();
        String team = sc.nextLine();

        char[] comerArr = comet.toCharArray();
        char[] teamArr = team.toCharArray();

        int cometInt = 1;
        for (char c : comerArr) {
            cometInt *= (c - 'A' + 1);
        }

        int teamInt = 1;
        for (char c : teamArr) {
            teamInt *= (c - 'A' + 1);
        }

        if ((cometInt % 47) == (teamInt % 47)) {
            System.out.println("GO");
        } else {
            System.out.println("STAY");
        }

        sc.close();
    }
}