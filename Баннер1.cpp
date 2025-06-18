#include <iostream>
#include <vector>
//#include <stack>
#include <algorithm>
using namespace std;

class Stack {
private:
    struct Node {
        int height;
        Node* next;
        Node() : height(), next(nullptr) {}
        Node(int h) : height(h), next(nullptr) {}
    };

    Node* top_node;

public:
    Stack() : top_node(nullptr) {}

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    void push(int height) {
        Node* new_node = new Node(height);
        new_node->next = top_node;
        top_node = new_node;
    }

    void pop() {
        if (empty()) return;
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
    }

    int top() const {
        return { top_node->height };
    }

    bool empty() const {
        return top_node == nullptr;
    }
};



int maxS(vector<int>& a) {
    int c = a.size();
    vector<int> left(c);
    vector<int> right(c);
    Stack  st;

    //Ближайший меньший слева
    for (int i = 0; i < c; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = -1;
        }
        else {
            left[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();

    //Ближайший меньший справа
    for (int i = c - 1; i >= 0; --i) {
        while (!st.empty() && (a[st.top()] >= a[i])) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = c;
        }
        else {
            right[i] = st.top();
        }
        st.push(i);
    }

    int max_s = 0;
    for (int i = 0; i < c; ++i) {
        max_s = max(max_s, a[i] * (right[i] - left[i] - 1)); //Максимальная площадь
    }
    return max_s;
}

void Tests() {
    {
        vector<int> t1 = { 2, 1, 5, 6, 2, 3 };
        int s = maxS(t1);
        if (s == 10) {
            cout << s << endl;
        }
        else {
            cout << "error test 1" << endl;
        }
    }
    {
        vector<int> t2 = { 4, 4, 4, 4 };
        int s = maxS(t2);
        if (s == 16) {
            cout << s << endl;
        }
        else {
            cout << "error test 2" << endl;
        }
    }

    {
        vector<int> t3 = { 1, 2, 3, 4, 5 };
        int s = maxS(t3);
        if (s == 9) {
            cout << s << endl;
        }
        else {
            cout << "error test 3" << endl;
        }
    }
    {
        vector<int> t4 = { 18 };
        int s = maxS(t4);
        if (s == 18) {
            cout << s << endl;
        }
        else {
            cout << "error test 4" << endl;
        }
    }
    {
        vector<int> t5 = { 0, 3, 0, 4, 0 };
        int s = maxS(t5);
        if (s == 4) {
            cout << s << endl;
        }
        else {
            cout << "error test 5" << endl;
        }
    }
    cout << endl;
}

int main() {
    Tests();
    return 0;
}