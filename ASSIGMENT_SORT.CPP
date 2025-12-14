
// ASSIGMENT DR.ASHRAF
#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[idx])
                idx = j;
        }
        int t = v[i];
        v[i] = v[idx];
        v[idx] = t;
    }
}

// Bubble Sort
void bubbleSort(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j+1]) {
                int t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
            }
        }
    }
}

// Linear Search
int linearSearch(vector<int>& v, int x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x)
            return i;
    }
    return -1;
}

// Binary Search 
int binarySearch(vector<int>& v, int x) {
    int l = 0;
    int r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == x)
            return mid;
        if (v[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}
struct NodeS {
    int val;
    NodeS* next;
};

class Stack {
    NodeS* top;

public:
    Stack() {
        top = nullptr;
    }
    void push(int v) {
        NodeS* n = new NodeS();
        n->val = v;
        n->next = top;
        top = n;
    }
    int pop() {
        if (top == nullptr)
            return -1;
        int x = top->val;
        NodeS* t = top;
        top = top->next;
        delete t;
        return x;
    }
    int peek() {
        return (top == nullptr ? -1 : top->val);
    }
};

struct NodeQ {
    int val;
    NodeQ* next;
};
class QueueLL {
    NodeQ* front;
    NodeQ* rear;
public:
    QueueLL() {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int v) {
        NodeQ* n = new NodeQ();
        n->val = v;
        n->next = nullptr;
        if (rear == nullptr) {
            front = n;
            rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }
    int dequeue() {
        if (front == nullptr)
            return -1;
        int x = front->val;
        NodeQ* t = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete t;
        return x;
    }
};

int main() {
    // Testing vector + sorting
    vector<int> v = {5, 3, 9, 1};
    bubbleSort(v);
    cout << "Bubble Sorted: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Searching
    cout << "Search 9 → " << linearSearch(v, 9) << endl;
    // Stack test
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Stack pop: " << st.pop() << endl;
    // Queue test
    QueueLL q;
    q.enqueue(11);
    q.enqueue(22);
    cout << "Queue dequeue: " << q.dequeue() << endl;
    return 0;
}
struct NodeL {
    int val;
    NodeL* next;
};
class LinkedList {
    NodeL* start;
public:
    LinkedList() {
        start = nullptr;
    }

    // insert at beginning
    void insertFirst(int v) {
        NodeL* n = new NodeL();
        n->val = v;
        n->next = start;
        start = n;
    }

    // insert at end
    void insertLast(int v) {
        NodeL* n = new NodeL();
        n->val = v;
        n->next = nullptr;
        if (start == nullptr) {
            start = n;
            return;
        }
        NodeL* t = start;
        while (t->next != nullptr)
            t = t->next;
        t->next = n;
    }

    // insert after a target value
    void insertAfter(int v, int target) {
        if (start == nullptr) return;
        NodeL* t = start;
        while (t != nullptr && t->val != target)
            t = t->next;
        if (t == nullptr) return;
        NodeL* n = new NodeL();
        n->val = v;
        n->next = t->next;
        t->next = n;
    }

    // delete first node
    void deleteFirst() {
        if (start == nullptr) return;
        NodeL* t = start;
        start = start->next;
        delete t;
    }

    // delete last node
    void deleteLast() {
        if (start == nullptr) return;
        // only 1 node
        if (start->next == nullptr) {
            delete start;
            start = nullptr;
            return;
        }
        NodeL* t = start;
        NodeL* prev = nullptr;
        while (t->next != nullptr) {
            prev = t;
            t = t->next;
        }
        prev->next = nullptr;
        delete t;
    }

    // delete specific value
    void deleteValue(int target) {
        if (start == nullptr) return;
        // delete first node
        if (start->val == target) {
            deleteFirst();
            return;
        }
        NodeL* prev = nullptr;
        NodeL* curr = start;
        while (curr != nullptr && curr->val != target) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) return;
        prev->next = curr->next;
        delete curr;
    }
};
