/*
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/*
template<class T>
class Value2Node {
    public:
    T value;
    Value2Node* left;
    Value2Node* right;
};
* /

template <class T>
class MinPQ {
public:
    virtual ~MinPQ() {};
    virtual bool empty() const = 0;
    virtual const T& top() const = 0;
    virtual void push(const T&) = 0;
    virtual void pop() = 0;
};

template <class T>
class MinHeap : public MinPQ<T> {
public:
    MinHeap() {
        _ct.push_back(T());
    };
    ~MinHeap() {};

    bool empty() const override {
        return !size();
    };

    const T& top() const override {
        if (empty()) throw std::out_of_range("heap is empty");
        return _ct[1];
    };

    void push(const T& obj) override {
        _ct.push_back(obj);
        _sift_up(size() - 1);
    };

    void pop() override {
        if (empty()) return;
        _ct[1] = _ct.back();
        _ct.pop_back();
        if (empty()) return;
        _sift_down(1);
    };

    size_t size() const {
        return _ct.size() - 1;
    };

private:
    // index getter
    size_t _i_left(size_t i) {
        return 2 * i;
    };
    size_t _i_right(size_t i) {
        return 2 * i + 1;
    };
    size_t _i_parent(size_t i) {
        return i / 2;
    };

    // sift er
    void _sift_up(size_t i) {
        while (i > 1 && _ct[i] < _ct[_i_parent(i)]) {
            std::swap(_ct[i], _ct[_i_parent(i)]);
            i /= 2;
        }
    };
    void _sift_down(size_t i) {
        while (_i_left(i) <= size()) {
            size_t min = _i_left(i);

            if (_i_right(i) <= size() && _ct[_i_right(i)] < _ct[_i_left(i)]) {
                min = _i_right(i);
            }

            if (_ct[i] <= _ct[min]) break;

            std::swap(_ct[i], _ct[min]);
            i = min;
        }
    };

private:
    vector<T> _ct;

};



int main() {
    try {
        MinHeap<int> min_heap;

        int a[] = { 5, 3, 8, 1, 2 };
        cout << "Test push: [5, 3, 8, 1, 2]" << endl;
        for (auto& v : a) {
            min_heap.push(v);
        }

        cout << "Test top:" << min_heap.top() << endl;
        cout << "Test size:" << min_heap.size() << endl;

        cout << "\nTest L<R:" << endl;
        // 1, 2, 3, 5, 8
        while (!min_heap.empty()) {
            cout << min_heap.top() << " ";
            min_heap.pop();
        }
        cout << endl;

        cout << "Test is empty:" << endl;
        if (min_heap.empty()) {
            cout << "Heap is empty" << endl;
        }

        cout << "top= " << endl;
        cout << min_heap.top() << endl;

    }
    catch (const std::out_of_range& e) {
        cout << "Catch error" << e.what() << endl;
    }
    catch (const std::exception& e) {
        cout << "other error" << e.what() << endl;
    }

    return 0;
}
*/
#include <iostream>
#include <cmath>
#include <random>
// #include <limits>

using namespace std;

template <class T>
class BST {         // left < right
private:
    class Node {
    public:
        T v;
        Node* left;
        Node* right;
        Node(T obj) : v(obj), left(nullptr), right(nullptr) {};
    };

public:
    BST() : _root(nullptr) {};

    void push(T obj) {
        if (!_root) _root = new Node(obj);
        else {
            Node* ptr = _root;
            while (true) {
                if (ptr->v == obj) return;  // repeat item not allowed
                if (ptr->v > obj) {
                    if (!ptr->left) {
                        ptr->left = new Node(obj);
                        return;
                    }
                    else ptr = ptr->left;
                }
                else {// <
                    if (!ptr->right) {
                        ptr->right = new Node(obj);
                        return;
                    }
                    else ptr = ptr->right;
                }
            }
        }
    };

    size_t height() const {
        return _get_height(_root);
    };

private:
    Node* _root;
    size_t _get_height(Node* node) const {
        if (node == nullptr)
            return 0;
        else
            return 1 + std::max(_get_height(node->right), _get_height(node->left));
    };
};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis;

    int test[] = { 100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };
    for (auto& v : test) {
        int n = v;
        double d = log2(v);
        BST<double> bst;
        while (v--) {
            double val = dis(gen);
            bst.push(val);
        };
        cout << "height/log2(" << n << ") = " << bst.height() / d << endl;
    }
}