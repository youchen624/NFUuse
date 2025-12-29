class Country {
    int 人口數;
    int 國土面積;
    int GDP;
    void showInfo() {
        System.out.printf("人口數: %d\n國土面積: %d\nGDP: %d\n", 人口數, 國土面積, GDP);
    };
}

/*

class Taiwan extends Country {
    static private Taiwan INSTANCE;
    static {
        // 1
        INSTANCE = new Taiwan();
    };
    private Taiwan() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("Taiwan:\n");
        super.showInfo();
    }
    // 2
    static Taiwan getInstance() {
        if (INSTANCE == null) INSTANCE = new Taiwan();
        return INSTANCE;
    };
}
 */

class Taiwan extends Country {
    private Taiwan() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    private static class H {
        private static final Taiwan INSTANCE = new Taiwan();
    }

    static public Taiwan getInstance() {
        return H.INSTANCE;
    };
}

public class CSIE_41343131_1226_3 {
    static public void main(String args[]) {
        Taiwan.getInstance().showInfo();
        Taiwan.getInstance().showInfo();
        Taiwan.getInstance().showInfo();
        Taiwan.getInstance().showInfo();
        Taiwan.getInstance().showInfo();
        Taiwan.getInstance().showInfo();
    };
}