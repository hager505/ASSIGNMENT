
#include <iostream>
using namespace std;
//STACK
class Stack {

public:
    int arr[100];
    int top;

    Stack(){
        top = -1;
    }

    void push(int item){
        if(top == 99)
            return;
        top++;
        arr[top] = item;
    }

    int pop(){
        if(top == -1)
            return -1;
        int x = arr[top];
        top--;
        return x;
    }

    int peek(){
        if(top == -1)
            return -1;
        return arr[top];
    }

    bool empty(){
        return (top == -1);
    }
};

//QUEUE
class Queue {

public:
    int arr[100];
    int front, rear;

    Queue(){
        front = 0;
        rear = -1;
    }

    void enqueue(int item){
        if(rear == 99)
            return;
        rear++;
        arr[rear] = item;
    }

    int dequeue(){
        if(front > rear)
            return -1;
        int x = arr[front];
        front++;
        return x;
    }

    bool empty(){
        return (front > rear);
    }

    int first(){
        if(front > rear)
            return -1;
        return arr[front];
    }
};

int main(){

    // Stack test
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "pop from stack: " << s.pop() << endl;

    // Queue test
    Queue q;
    q.enqueue(5);
    q.enqueue(15);
    cout << "dequeue from queue: " << q.dequeue() << endl;

    return 0;
}
