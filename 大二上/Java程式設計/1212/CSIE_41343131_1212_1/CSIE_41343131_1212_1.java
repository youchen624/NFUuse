import java.util.Scanner;

public class CSIE_41343131_1212_1 {
    static public class MyPoint {
        public double x = 0, y = 0;
        public MyPoint(double xx, double yy) {
            x = xx;
            y = yy;
        };
        public double distance(MyPoint b) {
            return Math.sqrt(Math.pow(this.x - b.x, 2) + Math.pow(this.y - b.y, 2));
        };
    };
    static public class MyPointSet {
        public enum Mode {
            min,
            average,
            max
        };
        public MyPointSet(MyPoint[] arr) {
            array = arr;
        };
        public MyPoint[] array;
        public double distance(MyPointSet ptsB, Mode mode) {
            double min = Double.POSITIVE_INFINITY, max = Double.NEGATIVE_INFINITY, total = 0;
            int t = 0;
            for (int ai = 0; ai < this.array.length; ++ai) {
                for (int bi = 0; bi < ptsB.array.length; ++bi) {
                    double tn = this.array[ai].distance(ptsB.array[bi]);
                    total += tn;
                    if (tn < min) min = tn;
                    if (tn > max) max = tn;
                    ++t;
                }
            }
            switch (mode) {
                case Mode.min:          return min;
                case Mode.max:         return max;
                case Mode.average:   return (t != 0) ? total / t : 0;
                default:                    return -1;
            }
        };
        public double distance(MyPointSet ptsB) {
            return distance(ptsB, Mode.min);
        };
    };
    static public void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String strA[] = (input.nextLine()).split(" ");
        String strB[] = (input.nextLine()).split(" ");
        MyPoint as[], bs[];
        as = new MyPoint[strA.length / 2];
        bs = new MyPoint[strB.length / 2];
        for (int i = 0, ti = 0; ti < strA.length; ++i, ti += 2) {
            as[i] = new MyPoint(Double.parseDouble(strA[ti]), Double.parseDouble(strA[ti + 1]));
        }
        for (int i = 0, ti = 0; ti < strB.length; ++i, ti += 2) {
            bs[i] = new MyPoint(Double.parseDouble(strB[ti]), Double.parseDouble(strB[ti + 1]));
        }
        MyPointSet A = new MyPointSet(as);
        MyPointSet B = new MyPointSet(bs);

        System.out.printf("%.4f\n", A.distance(B, MyPointSet.Mode.min));
        System.out.printf("%.4f\n", A.distance(B, MyPointSet.Mode.average));
        System.out.printf("%.4f\n", A.distance(B, MyPointSet.Mode.max));
        input.close();
    };
}
