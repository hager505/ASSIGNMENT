#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* next;
};
class LinkedList {
    Node* start;
public:
    LinkedList() {
        start = nullptr;
    }

    // insert at beginning
    void insertFirst(int v) {
        Node* n = new Node();
        n->val = v;
        n->next = start;
        start = n;
    }

    // insert at end
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

    // delete first node
    void deleteFirst() {
        if (start == nullptr) return;
        Node* t = start;
        start = start->next;
        delete t;
    }

    // delete last node
    void deleteLast() {
        if (start == nullptr) return;
        // only one node
        if (start->next == nullptr) {
            delete start;
            start = nullptr;
            return;
        }
        Node* prev = start;
        Node* curr = start->next;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
    }

    // delete specific value
    void deleteValue(int target) {
        if (start == nullptr) return;
        // delete first
        if (start->val == target) {
            deleteFirst();
            return;
        }
        Node* prev = start;
        Node* curr = start->next;
        while (curr != nullptr && curr->val != target) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) return;
        prev->next = curr->next;
        delete curr;
    }

    // display list for testing
    void display() {
        Node* t = start;
        while (t != nullptr) {
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList L;
    L.insertLast(10);
    L.insertLast(20);
    L.insertLast(30);
    L.insertLast(40);
    cout << "Initial List: ";
    L.display();
    L.deleteFirst();
    cout << "After deleteFirst: ";
    L.display();
    L.deleteLast();  
    cout << "After deleteLast: ";
    L.display();
    L.deleteValue(20);  
    cout << "After deleteValue(20): ";
    L.display();
    return 0;
}
