// import java.util.Scanner;

public class CSIE_41343131_1017_1 {
    public static void main(String args[]) {
        // Scanner 輸入 = new Scanner(System.in);
        int n = 10000;
        while (n <= 100000) {
            // double result = 1, sign = -1;
            // // int n = 輸入.nextInt();
            // int t = 1;
            // while (++t <= n) {
            // result += (sign * 1) / ((2 * t - 1));
            // sign *= -1;
            // }
            double result = pi(n);
            System.out.println(String.format("i = %6d, pi = %.10f", n, result));
            n += 10000;
        }
        int test_n = 100000;// 376850;
        double result = 0;
        result = pi(test_n);
        for (; Math.floor(result * 100000) != 314159;) {
            ++test_n;
            result = pi(test_n);
            // System.out.println("" + test_n);
        }
        System.out.println(String.format("\ni = %6d", test_n, result));
        // 輸入.close();
    };

    public static double pi(int max) {
        double result = 1, sign = -1;
        // int n = 輸入.nextInt();
        int t = 1;
        while (++t <= max) {
            result += (sign * 1) / ((2 * t - 1));
            sign *= -1;
        }
        return 4 * result;
    };
}
