import java.util.Scanner;

public class CSIE_41343131_1031_2 {
    static public void main(String[] args) {
        Scanner THE_INPUT = new Scanner(System.in);
        int L = 0;
        if (THE_INPUT.hasNext()) L = THE_INPUT.nextInt();
        int array[] = new int[L];
        for (int i = 0; i < L; ++i) {
            if (THE_INPUT.hasNext())
                array[i] = THE_INPUT.nextInt();
        }

        // System.out.print("[ ");
        // for (int i = 0; i < L; ++i) {
        //     if (i > 0) System.out.print(" ,");
        //     System.out.print(array[i]);
        // }
        // System.out.print(" ]");
        // System.out.print(" \n");
        array = strange_sort(array);
        // System.out.print("[ ");
        for (int i = 0; i < L; ++i) {
            if (i > 0) System.out.print(" ");
            System.out.print(array[i]);
        }
        // System.out.print(" ]");
        // System.out.print(" \n");

        THE_INPUT.close();
    };

    static public int[] strange_sort(int[] array) {
        for (int i = 0, max = 1; i < array.length - 1; ++i, max = i + 1) {
            for (int ii = max + 1; ii < array.length; ++ii) {
                if (array[ii] > array[max]) max = ii;
            }
            // if (min <= 0) continue;
            // int temp = array[i];
            array[i] = array[max];
            // array[max] = temp;
        }
        array[array.length-1] = -1;
        return array;
    };
}
