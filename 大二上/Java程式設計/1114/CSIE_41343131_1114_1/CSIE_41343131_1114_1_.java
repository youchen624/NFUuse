import java.util.Scanner;

public class CSIE_41343131_1114_1_ {
    static public void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String str1 = input.nextLine().toLowerCase();
            String str2 = input.nextLine().toLowerCase();

            str1.replaceAll("[^a-z]", "");
            str2.replaceAll("[^a-z]", "");

            // sort
            ;

            boolean is_anagrams = str1 == str2;

            System.out.println((is_anagrams) ? "Yes" : "No");
        };
        input.close();
    };

    static public String sort(String str) {
        char[] cstr = str.toCharArray();

        return str;
    };
    // static private 
};