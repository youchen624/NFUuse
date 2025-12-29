// Q1: Math
// 2025 11/07
// 41343131 youchen624
import java.util.Scanner;

public class w9Fs1{
    static public void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = 0;
        double res = 0;
        if (input.hasNext()) {
            n = input.nextInt();
            for(int i = 1; i <= n; ++i) {
                res += (i*i / (i + n));
            }
            System.out.printf("%.10f", res);
        }

        input.close();
    };
};