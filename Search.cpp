#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

// Linear Search
int linearSearch(vector<int>& v,int x){
    for(int i=0;i<v.size();i++){
        if(v[i]==x)
            return i;
    }
    return -1;
}

// Binary Search 
int binarySearch(vector<int>& v,int x){
    int l=0;
    int r=v.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid]==x)
            return mid;
        if(v[mid]>x)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

struct NodeS{
    int val;
    NodeS* next;
};

class Stack{
    NodeS* top;
public:
    Stack(){
        top=nullptr;
    }

    // Push element into stack
    void push(int v){
        NodeS* n=new NodeS();
        n->val=v;
        n->next=top;
        top=n;
    }

    // Pop element from stack
    int pop(){
        if(top==nullptr)
            return -1;
        int x=top->val;
        NodeS* t=top;
        top=top->next;
        delete t;
        return x;
    }

    // Get top element of stack
    int peek(){
        return(top==nullptr?-1:top->val);
    }
};

struct NodeQ{
    int val;
    NodeQ* next;
};

class QueueLL{
    NodeQ* front;
    NodeQ* rear;
public:
    QueueLL(){
        front=nullptr;
        rear=nullptr;
    }

    // Insert element into queue
    void enqueue(int v){
        NodeQ* n=new NodeQ();
        n->val=v;
        n->next=nullptr;
        if(rear==nullptr){
            front=n;
            rear=n;
            return;
        }
        rear->next=n;
        rear=n;
    }

    // Remove element from queue
    int dequeue(){
        if(front==nullptr)
            return -1;
        int x=front->val;
        NodeQ* t=front;
        front=front->next;
        if(front==nullptr)
            rear=nullptr;
        delete t;
        return x;
    }
};

int main(){
    // Testing vector + sorting
    vector<int> v={5,3,9,1};
    bubbleSort(v);
    cout<<"Bubble Sorted: ";
    for(int x:v) cout<<x<<" ";
    cout<<endl;

    // Searching
    cout<<"Search 9-> "<<linearSearch(v,9)<<endl;

    // Stack test
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"Stack pop: "<<st.pop()<<endl;

    // Queue test
    QueueLL q;
    q.enqueue(11);
    q.enqueue(22);
    cout<<"Queue dequeue: "<<q.dequeue()<<endl;

    return 0;
};