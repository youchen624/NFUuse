

public class CSIE_41343101_1219_1 {
    static public class ChainNode {
        public ChainNode() {
            next = prev = null;
        };
        public void setLink(ChainNode node) {
            next = node;
        };
        public ChainNode nextNode() {
            return next;
        };
        public void setData(int data_) {
            data = data_;
        };
        public int getData(int data_) {
            return data;
        };

        private ChainNode next, prev;
        private int data;
    };
    static public class Chain {
        public Chain() {
            head = null;
        };
        static public Chain getInstance() {
            return new Chain();
        };
        public ChainNode getNode() {
            // System.out.printf("G:1\n");
            if (head == null) {
                return new ChainNode();
            } else {
                ChainNode ptr = head;
                for (;ptr.next != null; ptr = ptr.next);
                if (ptr != head) {
                    ptr.prev = ptr.prev.next = null;
                }
                return ptr;
            }
        };
        public void retNode(ChainNode node) {
            System.out.printf("R:%d\n", node.data);
            if (head == null) {
                node.next = node.prev = null;
                head = node;
                return;
            }
            ChainNode ptr = head;
            for (;ptr.next != null; ptr = ptr.next);
            node.next = null;
            ptr.next = node;
            node.prev = ptr;
        };

        private ChainNode head;
    };
    static public void main(String[] args) {
        ChainNode node, first=null;
        Chain availableLinkedList = Chain.getInstance();

        // 利用呼叫 availableLinkedList.getNode() 取得空間，建立一個鏈結串列 1, 2, ..., 10
        for(int i=10; i>0; i--) {
            node = availableLinkedList.getNode();
            node.setLink(first);
            node.setData(i);
            System.out.printf("G:%d\n", node.data);
            first = node;
        }
        // 利用呼叫 availableLinkedList.retNode(node) 逐一歸還鏈結串列 1, 2, ..., 10 的記憶體空間
        while(first != null) {
            node = first;
            first = first.nextNode();
            availableLinkedList.retNode(node);
        }
    };
};