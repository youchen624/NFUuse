import java.util.Scanner;

public class CSIE_41343131_1031_4 {
    static public void main(String[] args) {
        Scanner THE_INPUT = new Scanner(System.in);
        int array_input[][] = new int[3][3];
        // input
        for (int i = 0; i < 3; ++i) {
            for (int ii = 0; ii < 3; ++ii) {
                if (THE_INPUT.hasNext())
                    array_input[i][ii] = THE_INPUT.nextInt();
            }
        }

        THE_INPUT.close();
    };

    static public int[] 行列式(int input_array[])
};