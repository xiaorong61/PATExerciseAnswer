import java.util.Scanner;

/**
 * pat1002
 */
public class pat1002 {
    static String[] pinyinMap = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

    static void printNumByPinyin(int num) {
        if (num >= 10) {
            printNumByPinyin(num / 10);
            System.out.print(' ');
        }
        System.out.print(pinyinMap[num % 10]);
    }

    static String tail(String str) {
        return str.substring(1);
    }

    static int sum(String str) {
        return str.length() == 0 ? 0 : str.charAt(0) - '0' + sum(tail(str));
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        printNumByPinyin(sum(in.next()));
        in.close();

    }
}