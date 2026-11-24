
class MyNumber {
    protected int data[];
    protected int size;
    protected int cap;
    public MyNumber() {
        size = 0;
        cap = 1;
        data = new int[cap];
    };

    protected void upgrade() {
        cap *= 2;
        int[] new_data = new int[cap];
        for (int i = 0; i < size; ++i) new_data[i] = data[i];
        data = new_data;
    };

    // 所有數總和
    long summation() {
        long t = 0;
        for (int i = 0; i < size; ++i) t += data[i];
        return t;
    };

    // 多少個整數(筆資料)
    int numElements() {
        return size;
    };

    // 印出全部
    void print() {
        for (int i = 0; i < size; ++i) System.out.print(data[i] + " ");
    };

    // 插入整數
    void insert(int num) {
        if (size >= cap) upgrade();
        data[size] = num;
        ++size;
    };
    void insert(int[] numList) {
        for(int n : numList) insert(n);
    };

    // 移除整數
    void remove(int num) {
        if (!contains(num)) return;
        else {
            int[] new_data = new int[cap];
            int new_size = 0;
            for(int i = 0; i < size; ++i)
                if (data[i] != num) {
                    new_data[new_size++] = data[i];
                }
            data = new_data;
            size = new_size;
            // --size;
        }
    };
    void remove(int[] numList) {
        for(int n : numList) remove(n);
    };
    void remove_index(int index) {
        // this.print(); System.out.print("\n");
        if(index >= size) return;   // or throw
        int[] new_data = new int[cap];
        int new_size = 0;
        for(int i = 0; i < size; ++i)
            if (i != index) {
                new_data[new_size++] = data[i];
            }
        data = new_data;
        size = new_size;
        // --size;
        // this.print(); System.out.print("\n");
    };

    // 查詢是否包含
    boolean contains(int num) {
        for (int i = 0; i < size; ++i)
            if (num == data[i]) return true;
            // else continue;
        return false;
    };

    void debug() {
        System.out.printf("#debug\nSize/Cap: %d/%d\n{[", size, cap);  // size == numElements
        // System.out.printf("Sum: %d\n{[", summation());
        for (int i = 0; i < cap; ++i) {
            System.out.print(data[i]);
            if (i + 1 == size) System.out.print("]");
            if (i + 1 != cap) System.out.print(", ");
        }
        System.out.printf("}\n#debug\n\n");
    };

    // void sort
};

// a < b
class SortedNumber extends MyNumber {
    SortedNumber() { super(); };

    void sort() {
        // System.out.print("before sort:\n"); debug();
        int[] new_data = new int[cap];
        int tsize = size;
        for (int i = 0, min_i = 0; i < tsize; ++i, min_i = 0) {
            for (int ti = 1; ti < size; ++ti) {
                if (data[ti] < data[min_i]) min_i = ti;
            } // min(int[])
            new_data[i] = data[min_i];
            remove_index(min_i);
        }
        data = new_data;
        size = tsize;
        // System.out.print("after sort:\n"); debug();
    };

    @Override
    void insert(int num) {
        if (size >= cap) upgrade();
        data[size] = num;
        ++size;
        sort();
    };
};

public class CSIE_41343131_0109_FINAL_EXAM {
    static public void ln() {
        System.out.print("\n");
    };
    static public void main(String[] args) {
        /*
        MyNumber mn = new MyNumber();
        for (int i = 0; i < 10; ++i) mn.insert(i);
        mn.print(); ln();
        int[] a = {1, 2, 5};
        mn.remove(a);
        mn.print(); ln();
        mn.insert(a);
        mn.print(); ln();
        System.out.println(mn.contains(40));
        System.out.println(mn.numElements());
        */


        System.out.print("\n---> MyNumber Test #BEGIN <---\n");

        // construts a MyNumber
        MyNumber mn = new MyNumber();
        System.out.println("Apends 0~9");
        for (int i = 0; i < 10; ++i) {
            mn.insert(i);
            mn.debug();
        }
        mn.print();
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            mn.summation(),
            mn.numElements()
        );

        System.out.println("Apends 10~0");
        for (int i = 10; i > 0; --i) {
            mn.insert(i);
            mn.debug();
        }
        mn.print();
        System.out.printf("\nis contains 6: %s", mn.contains(6));
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            mn.summation(),
            mn.numElements()
        );

        // insert with a list(array)
        System.out.println("inserts {3, 4, 5, 88, 0}");
        int[] b = {3, 4, 5, 88, 0};
        mn.insert(b);
        mn.print();
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            mn.summation(),
            mn.numElements()
        );

        // remove with a list(array)
        System.out.println("removes {3, 4, 5, 88, 0, 6, 10}");
        int[] c = {3, 4, 5, 88, 0, 6, 10};
        mn.remove(c);
        mn.print();
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            mn.summation(),
            mn.numElements()
        );

        System.out.printf("is contains 6: %s", mn.contains(6));

        System.out.print("\n---> MyNumber Test #END <---\n");

        // ######## ######## ######## ######## //
        // ######## ######## ######## ######## //
        // ######## ######## ######## ######## //
        // ######## ######## ######## ######## //   // 一堵相當堅固的#牆
        // ######## ######## ######## ######## //
        // ######## ######## ######## ######## //
        // ######## ######## ######## ######## //
        // ######## ######## ######## ######## //

        System.out.print("\n---> SortedNumber Test #BEGIN <---\n");

        // construts a SortedNumber
        SortedNumber sn = new SortedNumber();
        System.out.println("Apends 0~9");
        for (int i = 0; i < 10; ++i) {
            sn.insert(i);
            sn.debug();
        }
        sn.print();
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            sn.summation(),
            sn.numElements()
        );

        System.out.println("Apends 10~0");
        for (int i = 10; i > 0; --i) {
            sn.insert(i);
            sn.debug();
        }
        sn.print();
        System.out.printf("\nis contains 6: %s", sn.contains(6));
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            sn.summation(),
            sn.numElements()
        );

        // insert with a list(array)
        System.out.println("inserts {3, 4, 5, 88, 0}");
        // int[] b = {3, 4, 5, 88, 0};
        sn.insert(b);
        sn.print();
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            sn.summation(),
            sn.numElements()
        );

        // remove with a list(array)
        System.out.println("removes {3, 4, 5, 88, 0, 6, 10}");
        // int[] c = {3, 4, 5, 88, 0, 6, 10};
        sn.remove(c);
        sn.print();
        System.out.printf(
            "\nSum: %d\nElements: %d\n\n",
            sn.summation(),
            sn.numElements()
        );

        System.out.printf("is contains 6: %s", sn.contains(6));

        System.out.print("\n---> SortedNumber Test #END <---\n");

    };
};
