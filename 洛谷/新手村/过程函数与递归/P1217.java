import java.util.Scanner;

public class P1217 {

    /**
     * a, b代表区间
     * x, y代表位数
     */
    static int x, y, a, b;
    static int[] an = new int[10];//an这个数组是用来存储数字的, 之后再将这个数组转化为数字
    static boolean flag = false;//一个标记, 后面会谈到它的用途
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        a = sc.nextInt();
        b = sc.nextInt();

        x = digits(a);//a的位数
        y = digits(b);//b的位数

        //这里的for循环是起一个控制位数的作用, 将1位到9位的回文串依次搜索一遍, 且从一位的回文串开始
        for (int i = x; i <= y; i++) {
            if (i == 1) {
                if (a <= 5 && b >= 5) {
                    System.out.println(5);
                } 

                if (a <= 7 && b >= 7) {
                    System.out.println(7);
                }
                continue;
            }

            if (i == 2) {
                if (a <= 11 && b >= 11) {
                    System.out.println(11);
                }
                continue;
            }
            //偶数位数回文数（除11）必定不是质数（自行百度）
            if (i % 2 == 0) {
                continue;
            }

            if (i == 9) {
                break;
            }
            flag = false;

            //否则的话进行dfs搜索, 其中i代表搜索多少位的回文串
            dfs(0, i);
        }
        sc.close();
    }

    /**
     * 深度优先搜索, 不解释
     * @param x 代表目前枚举到了哪一位, 我们找回文串时利用了它回文的性质, 故只用找前一半就可以了
     * @param k 代表的是这一次的dfs所需要的的回文串的总位数
     */
    private static void dfs (int x, int k) {
        //如果if为true, 则代表找到了符合位数条件的回文串, 然后继续判断是否是素数, 记得最后一定要返回
        if (x == (k + 1) / 2) {
            for (int i = k; i > x; i--) {
                an[i] = an[k - i + 1];
            }
            int number = 0;
            for (int i = 1; i <= k; i++) {
                number = number * 10 + an[i];
            }
            if (number < a) return;
            if (number > b) {
                flag = true;
                return;
            }

            if (isPrime(number)) {
                System.out.println(number);
            }
            //一定要返回
            return;
        }

        int i;
        if ( x != 0) {
            i = 0;
        } else {
            i = 1;
        }
        for (; i <= 9; i++) {
            if (flag)
                return;
            an[x + 1] = i;
            dfs(x + 1, k);
        }
    }

    /**
     * 判断是否是素数的函数
     * @param num
     * @return 一个布尔值
     */
    private static boolean isPrime(int num) {
        if (num < 2) return false;
        else if (num == 2) return true;
        else {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    return false;
                } 
            }
            return true;
        }
    }
    
    /**
     * 判断一个数字有多少位的函数
     * @param num 数字
     * @return 数字的位数
     */
    private static int digits(int num) {
        int count = 0;
        while (num > 0) {
            num /= 10;
            count++;
        }
        return count;
    }
}