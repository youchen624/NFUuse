import java.util.Scanner;

public class CSIE_41343131_1031_1 {
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
            // if (i > 0) System.out.print(" ,");
            // System.out.print(array[i]);
        // }
        // System.out.print(" ]");
        // System.out.print(" \n");
        array = selection_sort(array);
        // System.out.print("[ ");
        for (int i = 0; i < L; ++i) {
            if (i > 0) System.out.print(" ");
            System.out.print(array[i]);
        }
        // System.out.print(" ]");
        // System.out.print(" \n");

        THE_INPUT.close();
    };

    static public int[] selection_sort(int[] array) {
        for (int i = 0, min = 0; i < array.length; ++i, min = i) {
            for (int ii = i + 1; ii < array.length; ++ii) {
                if (array[ii] < array[min]) min = ii;
            }
            if (min <= 0) continue;
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
        return array;
    };
}
