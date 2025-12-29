
public class CSIE_41343131_0926_1 {
    public static void main(String args[]) throws Exception {
        String 你的中文姓名_虎科大 = "虎科大陳宥儒";
        for (int i = 0; i < 你的中文姓名_虎科大.length(); i++) {
            char 你的中文姓名字 = 你的中文姓名_虎科大.charAt(i);
            System.out.println("" + 你的中文姓名字 + " " + (long) 你的中文姓名字);
        }
        /*
        double 任務 = 0;
        System.out.println("confirm to delete C: , Enter \"Y\" or \"N\":\nY\nDeleting whole C:/");
        while (true) {
            char[] 旋轉棒子 = { '\\', '|', '/', '-' };
            for (int 索引 = 0; 索引 < 旋轉棒子.length; 索引++) {
                System.out.printf("\r" + 旋轉棒子[索引] + '\t' + "%.3f" + "%%", 任務);
                Thread.sleep(100);
            }
            任務 += Math.random();
            if (任務 > 100.0) break;
        }
        System.out.print("\r-\t100.000%\nDelete Completed");
        */
    }
};