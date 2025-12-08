// Queue Lab01 

#include <iostream>
using namespace std;

#define MAX 5

class Queue {

    int q[MAX];
    int front;
    int rear;
    int count;

public:

    Queue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool full() {
        return (count == MAX);
    }

    bool empty() {
        return (count == 0);
    }

    int push(int value) {

        if (full())
            return -1;

        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        q[rear] = value;

        count++;
        return 1;
    }

    int pop() {

        if (empty())
            return -1;

        int temp = q[front];
        front = (front + 1) % MAX;

        count--;

        if (count == 0) {
            front = -1;
            rear = -1;
        }

        return temp;
    }

    int Front() {
        return empty() ? -1 : q[front];
    }

    int Back() {
        return empty() ? -1 : q[rear];
    }
};





// linkedlist Lab01

struct Node {
    int val;
    Node* next;
};

class List {

    Node* start;

public:

    List() {
        start = nullptr;
    }


    void insertFirst(int v) {

        Node* n = new Node();
        n->val = v;
        n->next = start;

        start = n;
    }

    void insertLast(int v) {

        Node* n = new Node();
        n->val = v;
        n->next = nullptr;

        if (start == nullptr) {
            start = n;
            return;
        }

        Node* t = start;
        while (t->next != nullptr)
            t = t->next;

        t->next = n;
    }

    void insertAt(int v, int pos) {

        if (pos == 1) {
            insertFirst(v);
            return;
        }

        Node* t = start;
        int k = 1;

        while (t != nullptr && k < pos - 1) {
            t = t->next;
            k++;
        }

        if (t == nullptr) return;

        Node* n = new Node();
        n->val = v;
        n->next = t->next;
        t->next = n;

    }

    void insertBefore(int v, int target) {

        if (start == nullptr) return;

        if (start->val == target) {
            insertFirst(v);
            return;
        }

        Node* prev = nullptr;
        Node* curr = start;

        while (curr != nullptr && curr->val != target) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return;

        Node* n = new Node();
        n->val = v;

        prev->next = n;
        n->next = curr;
    }


    void insertAfter(int v, int target) {
        if (start == nullptr) return;

        Node* t = start;

        while (t != nullptr && t->val != target) {
            t = t->next;
        }

        if (t == nullptr) return;

        Node* n = new Node();
        n->val = v;
        n->next = t->next;
        t->next = n;
    }



// Assignment  
// Deletion of first node.
    void deleteFirst() {
        if (start == nullptr) return;

        Node* t = start;
        start = start->next;
        delete t;
    }

// Deletion of the only node.
    void deleteOnlyNode() {
        if (start == nullptr) return;

        if (start->next == nullptr) {
            delete start;
            start = nullptr;
        }
    }

// Deletion in between the list.
    void deleteValue(int target) {

        if (start == nullptr) return;

        if (start->val == target) {
            deleteFirst();
            return;
        }

        Node* prev = nullptr;
        Node* curr = start;

        while (curr != nullptr && curr->val != target) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return;

        prev->next = curr->next;
        delete curr;
    }

// Deletion at the end.
    void deleteLast() {

        if (start == nullptr) return;

        if (start->next == nullptr) {
            delete start;
            start = nullptr;
            return;
        }

        Node* t = start;
        Node* prev = nullptr;

        while (t->next != nullptr) {
            prev = t;
            t = t->next;
        }

        prev->next = nullptr;
        delete t;
    }

};



// Doubly Linked List Lab01

struct DNode {
    int val;
    DNode* next;
    DNode* prev;
};

class DList {

    DNode* start;

public:

    DList() {
        start = nullptr;
    }

    void insertFirst(int v) {

        DNode* n = new DNode();
        n->val = v;
        n->next = start;
        n->prev = nullptr;

        if (start != nullptr)
            start->prev = n;

        start = n;
    }

    void insertLast(int v) {

        DNode* n = new DNode();
        n->val = v;
        n->next = nullptr;
        n->prev = nullptr;

        if (start == nullptr) {
            start = n;
            return;
        }

        DNode* t = start;
        while (t->next != nullptr)
            t = t->next;

        t->next = n;
        n->prev = t;
    }

    void deleteFirst() {

        if (start == nullptr) return;

        DNode* t = start;
        start = start->next;

        if (start != nullptr)
            start->prev = nullptr;

        delete t;
    }

    void deleteLast() {

        if (start == nullptr) return;

        if (start->next == nullptr) {
            delete start;
            start = nullptr;
            return;
        }

        DNode* t = start;
        while (t->next != nullptr)
            t = t->next;

        t->prev->next = nullptr;
        delete t;
    }

    void deleteValue(int target) {

        if (start == nullptr) return;

        if (start->val == target) {
            deleteFirst();
            return;
        }

        DNode* t = start;

        while (t != nullptr && t->val != target)
            t = t->next;

        if (t == nullptr) return;

        t->prev->next = t->next;

        if (t->next != nullptr)
            t->next->prev = t->prev;

        delete t;
    }
};



// Circular Linked List Lab01

struct CNode {
    int val;
    CNode* next;
};

class CList {

    CNode* start;

public:

    CList() {
        start = nullptr;
    }

    void insertFirst(int v) {

        CNode* n = new CNode();
        n->val = v;

        if (start == nullptr) {
            n->next = n;
            start = n;
            return;
        }

        CNode* t = start;

        while (t->next != start)
            t = t->next;

        n->next = start;
        t->next = n;
        start = n;
    }

    void insertLast(int v) {

        CNode* n = new CNode();
        n->val = v;

        if (start == nullptr) {
            n->next = n;
            start = n;
            return;
        }

        CNode* t = start;

        while (t->next != start)
            t = t->next;

        t->next = n;
        n->next = start;
    }

    void deleteFirst() {

        if (start == nullptr) return;

        if (start->next == start) {
            delete start;
            start = nullptr;
            return;
        }

        CNode* t = start;
        CNode* last = start;

        while (last->next != start)
            last = last->next;

        start = start->next;
        last->next = start;
        delete t;
    }

    void deleteLast() {

        if (start == nullptr) return;

        if (start->next == start) {
            delete start;
            start = nullptr;
            return;
        }

        CNode* prev = nullptr;
        CNode* t = start;

        while (t->next != start) {
            prev = t;
            t = t->next;
        }

        prev->next = start;
        delete t;
    }

    void deleteValue(int target) {

        if (start == nullptr) return;

        if (start->val == target) {
            deleteFirst();
            return;
        }

        CNode* prev = nullptr;
        CNode* t = start;

        while (t->next != start && t->val != target) {
            prev = t;
            t = t->next;
        }

        if (t->val != target) return;

        prev->next = t->next;
        delete t;
    }

};
 






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