import java.util.Scanner;

public class pat1010 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        boolean start = true;
        while (in.hasNextInt()) {
            int left = in.nextInt();
            int right = in.nextInt();
            if (left * right == 0) {
                if (start)
                    System.out.print("0 0");
                break;
            } else {
                if (start)
                    start = false;
                else
                    System.out.print(" ");
                System.out.print(left * right);
                System.out.print(" ");
                System.out.print(right - 1);
            }

        }
        in.close();
    }
}