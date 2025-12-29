import java.util.Scanner;

public class CSIE_41343131_1017_2 {
    public static void main(String args[]) {
        Scanner 輸入 = new Scanner(System.in);
        while(輸入.hasNext()) {
            int t = 輸入.nextInt();
            String str = String.format("%d is %swell-ordered number.", t, (isWellNumber((t)) ? "":"not "));
            System.out.println(str);
        }
        輸入.close();
    };

    public static boolean isWellNumber(int n) {
        if (n < 0) n *= -1;
        int min = n + 1;
        while(n > 0) {
            int t = n % 10;
            if (t >= min) return false;
            n /= 10;
            min = t;
        }
        return true;
    };
}