import java.util.Scanner;

public class CSIE_41343131_1208_1 {
    static public class MyComplexNumber {
        public MyComplexNumber() {
            this.real = 0;
            this.img = 0;
        };
        public MyComplexNumber(MyComplexNumber that) {
            this.real = that.real;
            this.img = that.img;
        };
        public MyComplexNumber(double real_, double img_) {
            this.real = real_;
            this.img = img_;
        };
        private double real, img;
        public String toString() {
            String str
                = String.format("%.3f", real) +
                ( img != 0 ? ((img<0)? " - ": " + ")
                + String.format("%.3f", Math.abs(img)) + "i" : "" );
            return str;
        };
        public MyComplexNumber add(MyComplexNumber that) {
            MyComplexNumber t = new MyComplexNumber(this);
            t.real += that.real;
            t.img += that.img;
            return t;
        };
        public MyComplexNumber sub(MyComplexNumber that) {
            MyComplexNumber t = new MyComplexNumber(this);
            t.real -= that.real;
            t.img -= that.img;
            return t;
        };
        public MyComplexNumber mul(MyComplexNumber that) {
            MyComplexNumber t = new MyComplexNumber();
            t.real = this.real * that.real + (-1) * this.img * that.img;
            t.img = this.real * that.img + that.real * this.img;
            return t;
        };
        public MyComplexNumber div(MyComplexNumber that) {
            MyComplexNumber t = new MyComplexNumber();
            t.real = this.mul(that.z()).real / (Math.pow(that.real, 2) + Math.pow(that.img, 2));
            t.img = this.mul(that.z()).img / (Math.pow(that.real, 2) + Math.pow(that.img, 2));;
            return t;
        };
        public MyComplexNumber z() {
            MyComplexNumber t = new MyComplexNumber(this);
            t.img *= -1;
            return t;
        };
    };
    static public void main(String args[]) {
        Scanner input = new Scanner(System.in);

        // a = a_real + a_img * i
        double a_real = input.nextDouble();
        double a_img = input.nextDouble();

        // b = b_real + b_img * i
        double b_real = input.nextDouble();
        double b_img = input.nextDouble();

        // create two complex number objects
        MyComplexNumber complexA = new MyComplexNumber(a_real, a_img);
        MyComplexNumber complexB = new MyComplexNumber(b_real, b_img);

        // add, sub, mul, div operations on these two complex numbers and print the results
        System.out.println(complexA.add(complexB));
        System.out.println(complexA.sub(complexB));
        System.out.println(complexA.mul(complexB));
        System.out.println(complexA.div(complexB));
        input.close();
    };
};