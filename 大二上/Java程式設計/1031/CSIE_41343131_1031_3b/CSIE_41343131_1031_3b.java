import java.util.Scanner;

public class CSIE_41343131_1031_3b {
    static public void main(String[] args) {
        Scanner THE_INPUT = new Scanner(System.in);
        int n = 0, num = 0;//, i_column =
        if (THE_INPUT.hasNext()) n = THE_INPUT.nextInt();
        if (THE_INPUT.hasNext()) num = THE_INPUT.nextInt();
        // while () {}
        int result[] = fine_index(n, num);

        if (result[0] > 0)
            System.out.printf("%d[%d, %d]", num, result[0], result[1]);
        else
            System.out.printf("not find %d in array.", num);

        THE_INPUT.close();
    };

    static public int[] fine_index(int n, int num) {
        int result[] = {0, 0};
        int i_row = 1;
        while (i_row < num) {
            if (i_row > n) {
                // not found.
                result[0] = -1;
                return result;
            }
            if (num > i_row)
                num -= i_row;
            else
                break;
            ++i_row;
        };
        result[0] = i_row;
        result[1] = num;
        return result;
    };
};