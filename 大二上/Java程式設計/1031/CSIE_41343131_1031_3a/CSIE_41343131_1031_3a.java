import java.util.Scanner;
public class CSIE_41343131_1031_3a {
    static public void main(String[] args) {
        Scanner THE_INPUT = new Scanner(System.in);
        int n = 0;
        if (THE_INPUT.hasNext()) n = THE_INPUT.nextInt();
        char c[][] = new char[0][0];

        for (int i = 0, f = 1; i < n; ++i, ++f) {
            for (int ii = 0; ii < f; ++ii) {
                System.out.print("*");
            }
            System.out.print("\n");
        }

        THE_INPUT.close();
    };
};