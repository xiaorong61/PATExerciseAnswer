import java.util.Scanner;

public class pat1011 {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        long[][] arr = new long[T][];
        for (int i = 0; i < T; i++) {
            long[] ABC = { in.nextLong(), in.nextLong(), in.nextLong() };
            arr[i] = ABC;
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.print("Case #");
            System.out.print(i + 1);
            System.out.print(": ");
            System.out.print(arr[i][0] + arr[i][1] > arr[i][2]);
            System.out.println();
        }
        in.close();

    }
}