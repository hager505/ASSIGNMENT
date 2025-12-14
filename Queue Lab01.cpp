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
