import java.util.Scanner;

public class CSIE_41343131_1003_3 {
    public static void main(String[] args) {
        Scanner 輸入 = new Scanner(System.in);
        int input = 輸入.nextInt(), n = 0;
        for(int x = 0; x <= 100000; ++x) {
            int t = 0;
            for(int y = 0; y < 6; ++y) {
                t += getN(x, y);
            }
            if (t == input) n++;
        }
        System.out.println(n);
        輸入.close();
    };

    public static int getN(int num, int index) {
        return (num / (int) Math.pow(10, index)) % 10;
        // return 0;
    };
};
// 100000
