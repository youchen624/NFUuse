class t {
    static int a = 1;       // (1)
    static {System.out.println("1");}
    int b = 0;                // (2)
    {System.out.println("2");}

    static { a = 2; }       // (3)
    static {System.out.println("3");}
    t() {System.out.println("4");a = 3; }             // (4)
    { b = 2; }                // (5)
    {System.out.println("5");}
}

public class CSIE_41343131_1226_1 extends t {
    int c = 2;                // (6)
    {System.out.println("6");}
    static { a = 4; }       // (7)
    static {System.out.println("7");}
    CSIE_41343131_1226_1() { System.out.println("8"); a = 5; }   // (8)
    { c = 3; }                 // (9)
    {System.out.println("9");}
    public static void main(String[] args) {
        System.out.println("10");
        CSIE_41343131_1226_1 b = new CSIE_41343131_1226_1();     // (10)
        // () meaning stack, "(" meaning begin, ")" meaning end (fully completed)
        // 1, 3, 7, 10( 8( 2, 5, 4(), 6, 9) )
    }
}