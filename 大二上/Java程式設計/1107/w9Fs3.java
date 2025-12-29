// Q3: Emirp
// 2025 11/07
// 41343131 youchen624

// import java.util.Scanner;

public class w9Fs3 {
    static public void main(String[] args) {
        /*
        Scanner input = new Scanner(System.in);
        if (input.hasNext()) {
            int n = input.nextInt();
            System.out.println(is_emirp(n));
        }
        input.close();
        */

        int t = 0, i = 1;
        while (t < 105) {
            if (is_emirp(++i)) {
                ++t;
            }
        }

        System.out.println(i);

    };

    // a function to determine is the numer is an "Emirp".
    static public boolean is_emirp(int x) {
        if (x <= 12) return false;
        if (x % 2 == 0) return false;
        String str, str_inv = "";
        str = String.valueOf(x);

        // inverse string
        for (int i = str.length() - 1; i >= 0 ; --i) {
            str_inv += str.charAt(i);
        }

        // inverse int value
        int x_inv = parseInt(str_inv);
        if (x == x_inv) return false;

        // detecting is Emirp by for-loop
        for (int i = x - 1; i > 1; --i) {
            if (x % i == 0) return false;
        }
        for (int i = x_inv - 1; i > 1; --i) {
            if (x_inv % i == 0) return false;
        }
        // System.out.printf("this is: %d\n", x);
        return true;
    };

    // a function to parse the String to int
    static int parseInt(String str) {
        int res = 0;
        for (int p = 1, i = str.length() - 1; i >= 0; --i, p *= 10) {
            char c = str.charAt(i);
            // if ((i == 0) && (c == '-')) return res * -1;
            if (c < '0' || c > '9') throw new Error("Invalid number string.");
            res += p * (c - '0');
        }
        return res;
    };
}
