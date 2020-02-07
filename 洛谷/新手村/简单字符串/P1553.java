import java.util.Scanner;

public class P1553 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String resStr;

        if(str.indexOf('/') != -1) {
            String[] strArr = str.split("/");
            String numerator = strArr[0];
            String denominator = strArr[1];
            
            resStr = removeStartZero(reverseString(numerator)) + "/" + removeStartZero(reverseString(denominator));
        } else if (str.indexOf('.') != -1) {
            //*** important *** re expression, so in front of the "." should add \\
            String[] strArr = str.split("\\.");
            String numerator = strArr[0];
            String denominator = strArr[1];

            resStr = removeStartZero(reverseString(numerator)) + "." + reverseString(removeStartZero(denominator));
        } else if (str.indexOf('%') != -1) {
            String[] strArr = str.split("%");
            String numerator = strArr[0];

            resStr = removeStartZero(reverseString(numerator)) + "%";
        } else {
            resStr = removeStartZero(reverseString(str));
        }
        System.out.println(resStr);
        sc.close();

    }

    private static String reverseString (String value) {
        StringBuffer s = new StringBuffer(value);
        return s.reverse().toString();
    }  

    private static String removeStartZero(String value) {
		int index = -1;
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < value.length(); i++) {
			if (value.charAt(i) == '0') {
				index = i;
			} else {
				break;
			}
        }
        //important
		if (value.length() == index + 1) {
			sb = new StringBuffer("0");
		} else if (-1 != index) {
			sb = new StringBuffer(value.substring(index + 1, value.length()));
		} else {
			sb = new StringBuffer(value);
		}
		return sb.toString();
	}
}

