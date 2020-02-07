import java.util.Scanner;
/**
 * P1579
 */
public class P1579 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        if (isPrime(n - 4)) {
            System.out.printf("%d %d %d", 2, 2, n - 4);
        }

        else {
            for (int i = 3; i < 20000; i++){
                for (int j = 3; j < 20000; j++) {
                    if (isPrime(i) && isPrime(j)) {
                        if (isPrime(n - i - j)) {
                            System.out.printf("%d %d %d", i, j, n - i - j);
                            return;
                        }
                    }
                }
            }
        }
       
    }

    private static boolean isPrime(int num) {
        if (num < 2) return false ;
        else if (num == 2) return true;
        else {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0)
                    return false;
            }
            return true;
        }
    }

   // private static void dfs(int k, )

    // private static List<Integer> primes(int max) {
    //     List<Integer> list = new ArrayList<>();

    //     list.add(0);
    //     for (int i = 1; i <= max; i++) {
    //         list.add(i);
    //     }

    //     for (int i = 2; i * i <= max; i++) {
    //         if (list.get(i) != 0) {
    //             //这里直接忽略小于i的倍数, 因为之前已经处理过了
    //             int a = i * i;
    //             while (a <= max) {
    //                 list.set(a, 0);
    //                 a += i;
    //             }
    //         }
    //     }

    //     return list.stream().filter(i -> i != 0).collect(Collectors.toList());
    // }
}