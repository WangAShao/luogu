import java.util.Arrays;

public class P1008 {
    public static void main(String[] args) {
        for (int i = 123; i <= 329; i++) {
            int j = 2 * i;
            int k = 3 * i;

            String result = "" + i + j + k;
            char[] ar = result.toCharArray();
            Arrays.sort(ar);
            String sorted = String.valueOf(ar);

            if (sorted.equals("123456789") ) {
                System.out.printf("%d %d %d\n", i, j, k);
            } 
        }
    }
}