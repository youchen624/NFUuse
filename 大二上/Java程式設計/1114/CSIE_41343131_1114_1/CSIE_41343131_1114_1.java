import java.util.Scanner;

public class CSIE_41343131_1114_1 {
    static public void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            int[] charCount = new int[26];
            String str1 = input.nextLine().toLowerCase();
            String str2 = input.nextLine().toLowerCase();

            for (int i = 0; i < str1.length(); ++i) {
                char c = str1.charAt(i);
                if ('a' <= c && c <= 'z') ++charCount[c-'a'];
            }
            for (int i = 0; i < str2.length(); ++i) {
                char c = str2.charAt(i);
                if ('a' <= c && c <= 'z') --charCount[c-'a'];
            }

            boolean is_anagrams = true;
            for (int i = 0; i < 26; ++i) {
                if (charCount[i] > 0) {
                    is_anagrams = false;
                    break;
                }
            }
            System.out.println((is_anagrams) ? "Yes" : "No");
        };
        input.close();
    };
};