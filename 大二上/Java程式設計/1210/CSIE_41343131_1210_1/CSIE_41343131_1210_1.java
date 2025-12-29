public class CSIE_41343131_1210_1 {
    static public class Account {
        String _name;
        int _bank;

        public Account(String name) {
            this._name = name;
        };

        void deposit(int n) {
            this._bank += n;
        };
        void withdraw(int n) {
            this._bank -= n;
        };

        void transfer(Account that, int value) {
            this.withdraw(value);
            that.deposit(value);
        };

        String getName() {
            return this._name;
        };
        int balancing() {
            return this._bank;
        }
    };
    static public void main(String args[]) {
        // create a class Account such that the following codes in main() could successfully run.
        Account john = new Account("John");
        Account mary = new Account("Mary");
        john.deposit(500);  // 存入 500 元到 John 戶頭
        john.withdraw(200); // 從 John 戶頭提領 200 元
        john.transfer(mary, 100); // 從  John 戶頭轉帳 100 元到 Mary 戶頭
        System.out.println(john.getName()+"'s balancing is "+john.balancing());
        System.out.println(mary.getName()+"'s balancing is "+mary.balancing());
    };
};