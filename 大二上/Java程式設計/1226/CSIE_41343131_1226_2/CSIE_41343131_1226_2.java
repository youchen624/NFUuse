class Country {
    int 人口數;
    int 國土面積;
    int GDP;
    void showInfo() {
        System.out.printf("人口數: %d\n國土面積: %d\nGDP: %d\n", 人口數, 國土面積, GDP);
    };
}

class Taiwan extends Country {
    Taiwan() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("Taiwan:\n");
        super.showInfo();
    }
}
class German extends Country {
    German() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("German:\n");
        super.showInfo();
    }
}
class England extends Country {
    England() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("England:\n");
        super.showInfo();
    }
}
class Japan extends Country {
    Japan() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("Japan:\n");
        super.showInfo();
    }
}
class Korea extends Country {
    Korea() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("Korea:\n");
        super.showInfo();
    }
}
class America extends Country {
    America() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("America:\n");
        super.showInfo();
    }
}
class France extends Country {
    France() {
        this.人口數 = 0;
        this.國土面積 = 0;
        this.GDP = 0;
    }
    void showInfo() {
        System.out.print("France:\n");
        super.showInfo();
    }
}


public class CSIE_41343131_1226_2 {
    static public void main(String args[]) {
        // (沒有人類以前)
        new Taiwan().showInfo();
        new German().showInfo();
        new England().showInfo();
        new Japan().showInfo();
        new Korea().showInfo();
        new America().showInfo();
        new France().showInfo();
    };
}