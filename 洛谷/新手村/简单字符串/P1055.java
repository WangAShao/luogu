import java.util.*;
import java.io.*;

public class P1055 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String isbn = sc.nextLine();

        int count = Integer.parseInt(isbn.substring(0, 1));
        for (int i = 2; i < 5; i++) {
            count += Integer.parseInt(isbn.substring(i, i + 1)) * i;
        }

        for (int i = 6; i < 11; i++) {
            count += Integer.parseInt(isbn.substring(i, i + 1)) * (i - 1);
        }

        count %= 11;
        char c;
        if (count < 10) {
            c = (char)(count + '0');
        } else {
            c = 'X';
        }

        if (isbn.charAt(12) == c) {
            System.out.println("Right");
        } else {
            System.out.println(isbn.substring(0, 12) + c);
        }

        sc.close();
    }
}