import java.util.Scanner;

public class CSIE_41343131_1128_1 {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        towerHanoi(n, 'A', 'B', 'C');
        input.close();
    };

    public static void towerHanoi(int n, char a, char b, char c) {
        /**
         * @function towerHanoi sim tower of Hanoi.
         * @returns none
         * @date 2025 1128
         * @author youchen624
         * @param n { int } plates count
         * @param a b c { char } name of tower
         */
        if (n-1 == 0) {
            System.out.println("" + n + " from " + a + " to " + c + ".");
        } else {
            towerHanoi(n - 1, a, c, b);
            System.out.println("" + n + " from " + a + " to " + c + ".");
            towerHanoi(n - 1, b, a, c);
        }
    };
};