import java.util.Scanner;

public class CSIE_41343131_1003_1 {
    public static void main(String[] args) {
        Scanner 輸入 = new Scanner(System.in);
        while (輸入.hasNext()) {
            int a = 輸入.nextInt(), b = 輸入.nextInt();
            // System.out.println(String.valueOf(a));
            // System.out.println(String.valueOf(b));
            // #### swap ####
            a ^= b;
            b ^= a;
            a ^= b;
            // #### end. ####
            System.out.println(String.valueOf(a));
            System.out.println(String.valueOf(b));
        }
        輸入.close();
    };
};