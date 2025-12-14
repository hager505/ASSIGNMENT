// Circular Linked List Lab01
#include <iostream>
using namespace std;
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

    // Insert at beginning
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

    // Insert at end
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

    // Delete first node
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

    // Delete last node
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

    // Delete specific value
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

    // Display list
    void display() {
        if (start == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        CNode* t = start;
        do {
            cout << t->val << " ";
            t = t->next;
        } 
        while (t != start);
        cout << endl;
    }

};

int main() {
    CList c;
    c.insertFirst(10);
    c.insertFirst(5);
    c.insertLast(20);
    c.insertLast(30);
    cout << "List: ";
    c.display();
    c.deleteFirst();
    cout << "After delete first: ";
    c.display();
    c.deleteLast();
    cout << "After delete last: ";
    c.display();
    c.deleteValue(20);
    cout << "After delete 20: ";
    c.display();
    return 0;
}
