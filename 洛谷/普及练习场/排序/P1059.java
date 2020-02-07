import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
/**
 * P1059
 */
public class P1059 {
    public static void main(String[] args) {
        Set<Integer> set = new TreeSet<Integer>();
        Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();   
            for(int i=0;i<n;i++)    set.add(sc.nextInt());  sc.close();

            System.out.println(set.size()+"\n"+set.toString().replaceAll(",", "").
            substring(1,set.toString().length()-set.size()));
    }

}