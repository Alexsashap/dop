## Дополнительное задание. Реализовать алгоритм нахождение максимальной площади прямоугольного баннера
В ходе реализации данного задания была реализована структура хранения данных Stack, для которой реализованы функции push, pop, top, empty.
```
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
```
При реализации алгоритма нахождения наибольшей площади были реализованы отдельно функции нахождения ближайщего наименьшего элемента слева и справа
```
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
```
В качестве тестов рассмотрела 5 вариантов:
В тесте номер один рассмотрела общий вариант, когда дома расположены хаотично и при таких исходных данных программа выдает 10
```
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
```
В тесте номер 2 рассматривается вариант, когда высота домов одинаковая и баннер можно повесить на всю площадь = 16
```
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
```
В тесте номер 3 рассматривается вариант, когда наибольшая площадь достигается при прямоугольнике 3 на 3
```
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
```
В тесте номер 4 рассматривается вариант, когда на выделенном пространстве находится только один дом  
```
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
```
А в варианте номер 5 рассматривается вариант, где между домами есть промежутки. 
```
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
```
