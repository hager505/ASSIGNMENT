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
};