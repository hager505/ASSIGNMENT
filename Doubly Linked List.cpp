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
