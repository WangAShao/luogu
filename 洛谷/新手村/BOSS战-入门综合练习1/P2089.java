import java.util.Scanner;

/**
 * P2089
 */
public class P2089 {

    static int[][] m1 = new int[10000][10];
    static int[] m2 = new int[10];
    static int kinds = 0;
    static int sum;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sum = sc.nextInt();
        sc.close();
        dfs(0, 0);
        System.out.println(kinds);

        for (int i = 0; i < kinds; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.printf("%d ", m1[i][j]);
            }
            System.out.println("");
        }
    }

    private static void dfs(int k, int s) {
        if (k == 10) {
            if (s == sum) {
                for (int i = 0; i < 10; i++) {
                    m1[kinds][i] = m2[i];
                }
                kinds++;
            }
        }

        else if (s >= sum) {
            return;
        } else {
            for (int i = 1; i <= 3; i++) {
                m2[k] = i;
                dfs(k + 1, s + i);
            }
        }
    }
}

//下面的方法运行起来快一些

// import java.util.*;
// public class Main {
 
// 	private static int ans=0;
// 	private static String[] str=new String[10005];
 
// 	public static void main(String[] args) {
// 		// TODO Auto-generated method stub
// 		Scanner in=new Scanner(System.in);
// 		int n=in.nextInt();
// 		dfs(n,0,"",10);
// 		System.out.println(ans);
// 		for(int i=0;i<ans;i++)
// 		{
// 			for(int j=0;j<str[i].length();j++)
// 			{
// 				if(j==str[i].length()-1)
// 					System.out.print(str[i].charAt(j));
// 				else
// 					System.out.print(str[i].charAt(j)+" ");
// 			}
// 			System.out.println();
// 		}
		
// 	}
 
// 	private static void dfs(int n, int sum,String s,int cnt) {
// 		if(cnt==0)
// 		{
// 			if(sum==n)
// 			{
// 				str[ans]=s;
// 				ans++;
// 			}
// 			s="";
// 			return;
// 		}
// 		dfs(n,sum+1,s+"1",cnt-1);
// 		dfs(n,sum+2,s+"2",cnt-1);
// 		dfs(n,sum+3,s+"3",cnt-1);
// 	}
 
// }
