import java.util.Scanner;

/**
 * P1098
 */
public class P1098 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int p1 = sc.nextInt();
        int p2 = sc.nextInt();
        int p3 = sc.nextInt();

        String str = sc.next();
        sc.close();

        char[] ch = str.toCharArray();

        char before, after, now, p;
        char j;

        System.out.print(ch[0]);
        for (int i = 1; i < ch.length - 1; i++) {
            before = ch[i - 1];
            after = ch[i + 1];
            now = ch[i];

            if (now == '-' && after > before && (before >= '0' && after <= '9' || before >= 'a' && after <= 'z')) {
                if (p3 == 1) {
                    for (j = ++before; j < after; j++) {
                        p = j;

                        if (p1 == 2) {
                            //说明是大写
                            p = (p > 'a') ? (char)(p - 32) : p;
                        } else if (p1 == 3) {
                            p = '*';
                        }for (int k = 0; k < p2 ; k++) {
                            System.out.print(p);
                        }

                    }
                } else {
                    for (j = --after; j > before; j--) {
                        p = j;

                        if (p1 == 2) {
                            //说明是大写
                            p = (p > 'a') ? (char)(p - 32) : p;
                        } else if (p1 == 3) {
                            p = '*';
                        }for (int k = 0; k < p2 ; k++) {
                        System.out.print(p);
                        }                      
                    }                
                }

                
            } else {
                System.out.print(now);
            }
        }

        System.out.println(ch[ch.length - 1]);
    }
}