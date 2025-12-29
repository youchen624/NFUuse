import java.util.Scanner;

public class CSIE_41343131_1128_2 {
    /*  // 2025 1128 12:08
    (a)設計一個向量類別 Vector,
    (b)用Vector 類別建立二個向量物件 vecA=(1,2,3), vecB=(4,5,6)
    (c)計算 vecA 與 vecB 的長度(norm), 並印出
    (d)計算此二個向量的內積結果並印出
    (e)重複上述(b)-(d), 但vecA=(1,2,3,4,5,6,7,8,9,10), vecB=(11,12,13,14,15,16,17,18,19,20)
    */
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] array1 = new int[n];
        int[] array2 = new int[n];
        for (int i = 0; i < n; ++i) {
            array1[i] = input.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            array2[i] = input.nextInt();
        }
        Vector vecA = new Vector(array1);
        Vector vecB = new Vector(array2);

        System.out.printf("%.4f\n", vecA.norm());
        System.out.printf("%.4f\n", vecB.norm());
        System.out.printf("%.4f", Vector.product(vecA, vecB));

        input.close();
        /*
        vecA = new Vector(1,2,3,4,5,6,7,8,9,10);
        vecB = new Vector(11,12,13,14,15,16,17,18,19,20);
        
        System.out.printf("%.4f", vecA.norm());
        System.out.printf("%.4f", vecB.norm());
        System.out.printf("%.4f", Vector.product(vecA, vecB));
        */
    };

    static public class Vector {
        int v[];

        public Vector(int... values) {
            this.v = values;
        };

        public double norm() {
            // | v | =
            int total = 0;
            for (int i : v) {
                total += i * i;
            }
            return (double) Math.sqrt(total);
        };

        static public double product(Vector a, Vector b) {
            if (a.v.length != b.v.length) throw new Error("Different dimension.");
            double t = 0;
            for (int i = 0; i < a.v.length; ++i) {
                t += a.v[i] * b.v[i];
            }
            return t;
        };
    };
};