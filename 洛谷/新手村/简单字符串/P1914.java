import java.util.Scanner;
import java.lang.String;

public class P1914 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String text = sc.next();

        char[] textArr = text.toCharArray();
        int len = textArr.length;
        for (int i = 0; i < len; i++) {
            char temp = (char) ((textArr[i] - 'a' + n) % 26 + 'a');
            textArr[i] = temp;
            //System.out.println(temp);
        }

        text = new String(textArr);
        System.out.println(text);

        
    }
}