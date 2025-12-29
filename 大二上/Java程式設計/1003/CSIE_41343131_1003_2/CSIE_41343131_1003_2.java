import java.util.Scanner;

public class CSIE_41343131_1003_2 {
    public static void main(String[] args) {
        Scanner 輸入 = new Scanner(System.in);
        int a = 輸入.nextInt(), b = 輸入.nextInt(), c = 輸入.nextInt();
        int total = a + b + c;
        int min = (a < b ? (a < c ? a : c) : (b < c ? b : c));
        int max = (a > b ? (a > c ? a : c) : (b > c ? b : c));
        System.out.println("" + min);
        System.out.println("" + (total-min-max));
        System.out.println("" + max);
        輸入.close();
    };
};