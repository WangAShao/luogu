import java.util.*;

/**
 * P1540
 */
public class P1540 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = sc.nextInt();
        int N = sc.nextInt();

        Set<Integer> s = new HashSet<>();
        Queue<Integer> q = new LinkedList<>();

        int count = 0;
        int capacity = 0;
        int a;
        for (int i = 0; i < N; i++) {
            a = sc.nextInt();

            if (!s.contains(a)) {
                count++;
                if (capacity == M) {
                    int temp = q.poll();
                    s.remove(temp);

                    q.offer(a);
                    s.add(a);
                } else {
                    //内存容量足够
                    q.offer(a);
                    s.add(a);
                    capacity++;
                }
            } else {
                //内存包含这个单词
                continue;
            }
        }
        System.out.println(count);

    }
}
