import java.util.Scanner;

public class CSIE_41343131_0926_3 {
    public static void main(String args[]) {
        Scanner 輸入 = new Scanner(System.in);
        int 分數;
        while (輸入.hasNext()) {
            String 輸入字串 = 輸入.next();
            分數 = Integer.parseInt(輸入字串);
            // System.out.println("test:" + a);
            if (分數 >= 60)
                System.out.println("及格");
            else if (分數 < 50)
                System.out.println("不及格");
            else
                System.out.println("補考");
        }
        輸入.close();
    }
}
