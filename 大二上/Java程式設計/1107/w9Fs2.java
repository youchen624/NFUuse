// Q2: Distances and Fees
// 2025 11/07
// 41343131 youchen624


// import java.util.Scanner;

public class w9Fs2 {
    static public void main(String[] args) {
        // Scanner input = new Scanner(System.in);

        // position (km)
        int array[] = { 25, 49, 95, 178, 264, 327, 373};

        // form of distances
        for(int i = 0; i < array.length; ++i) {
            for(int ii = 0; ii < array.length; ++ii) {
                System.out.print(Math.abs(array[i] - array[ii]));
                System.out.print(" ");
            }
            System.out.println();
        }
        // form of fees
        for(int i = 0; i < array.length; ++i) {
            for(int ii = 0; ii < array.length; ++ii) {
                System.out.printf("%.10f",f(Math.abs(array[i] - array[ii])));
                System.out.print(" ");
            }
            System.out.println();
        }
    };

    // bus.inc fee logic
    // #warn# problem should be fixed, there are at least 2 errors !!
    static public double f(int x) {
        // the problem has some errors:
        // 1. at X = 50+ ~ 51-, there is no result
        // 2. at X = 200, there are 2 RESULTS !!
        if (x <= 50) return (double)x * 2.5;
        else if (51 <= x && x <= 200) return (double)x * 2.2;
        else if (x >= 200) return (double)x * 2;
        return 0;
    };
}
