import java.util.Scanner;

public class P1308 {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        String pattern = sc.nextLine().toLowerCase();
        pattern = pattern.trim();

        String s = sc.nextLine().toLowerCase();
        int count = 0;
        int index = 0;
        int flag = 0;

        String[] ss = s.split(" ");

        for (int i = 0; i < ss.length; i++) {
            if (ss[i].equals(pattern)){
                count++;
            }
            if (count == 1) flag = 1;
            if (flag == 0) {
                index += ss[i].length() +1;
            }
        }

        if (count == 0) {
            System.out.println("-1");
        } else {
            System.out.println(count + " " + index);
        }

        sc.close();
    }
}