import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Comparator;

/**
 * P1086 这一题被我自己蠢到了, 注意题目, 每一次都要取剩下的里面的最大的, 贪心足矣
 */
public class P1086 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        List<int[]> list = new ArrayList<>();
        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int x = sc.nextInt();
                if (x > 0){
                    int[] p = {i, j, x, 0};//记录坐标, 花生数
                    list.add(p);
                }
            }
        }
        sc.close();

        //讲真, 这一段排序我没有理解为什么这么写
        list.sort(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[2] > o2[2]) {
                    return -1;
                } else if (o1[2] < o2[2]) {
                    return 1;
                } else {
                    return 0;
                }
            }
        });

        int ans = 0;
        //从路边到第一个的时间等于第一个的纵坐标的值
        list.get(0)[3] = list.get(0)[0];
        if (k - list.get(0)[3] - 1 >= list.get(0)[0]) {
            ans += list.get(0)[2];
            list.get(0)[3] += 1;
        }

        for (int i = 1; i < list.size(); i++) {
            int time = list.get(i - 1)[3];
            int row1 = list.get(i - 1)[0];
            int colum1 = list.get(i - 1)[1];
            int row2 = list.get(i)[0];
            int colum2 = list.get(i)[1];

            int s = list.get(i)[2];

            //去往下一个的时间
            time += Math.abs(row2 - row1) + Math.abs(colum2 - colum1);
            if (time + row2 + 1 > k) {
                //那么就说明采摘了这个就回不去了
                break;
            }
            
            ans += s;
            time += 1;
            list.get(i)[3] = time;
        }

        System.out.println(ans);
    }
}