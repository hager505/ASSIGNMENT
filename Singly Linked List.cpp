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