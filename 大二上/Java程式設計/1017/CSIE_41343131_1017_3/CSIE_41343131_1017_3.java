import java.util.Scanner;

public class CSIE_41343131_1017_3 {
    public static void main(String args[]) {
        Scanner 輸入 = new Scanner(System.in);
        while (輸入.hasNext()) {
            String raw_data = 輸入.next();
            StringBuilder data = new StringBuilder(raw_data);
            int length = data.length();
            for (int i = 0; i < length / 2; ++i) {
                char t = data.charAt(i);
                data.setCharAt(i, data.charAt(length - i - 1));
                data.setCharAt(length - i - 1, t);
            }
            System.out.println(Integer.valueOf(data.toString()));
        }
        輸入.close();
    };
}