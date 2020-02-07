import java.util.Scanner;

/**
 * P1307
 */
public class P1307 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String result = "";
        if (str.charAt(0) == '-') {
            result = "-" + removeZero(reverse(removeZero(str.substring(1, str.length()))));
        } else {
            result = removeZero(reverse(removeZero(str)));
        }

        System.out.println(result);
        sc.close();
    }

    private static String removeZero(String str) {
        int index = -1;
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '0') {
                index = i;
            } else {
                break;
            }
        }
        if (str.length() == index + 1) {
            sb = new StringBuffer("0");
        } else if (index != -1) {
            sb = new StringBuffer(str.substring(index + 1, str.length()));
        } else {
            sb = new StringBuffer(str);
        }
        return sb.toString();
    }

    private static String reverse(String str) {
        StringBuffer sb = new StringBuffer(str);
        return sb.reverse().toString();
    }
}