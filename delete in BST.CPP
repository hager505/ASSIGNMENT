#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    Node* root;
    BST(){
        root = NULL;
    }
    Node* Insert(Node* r, int item){
        if(r == NULL){
            Node* n = new Node(item);
            r = n;
        }
        else if(item < r->data)
            r->left = Insert(r->left, item);
        else
            r->right = Insert(r->right, item);

        return r;
    }
    void Insert(int item){
        root = Insert(root, item);
    }
    //Delete in BST
    Node* Delete(Node* r, int key){
        if(r == NULL)
            return r;
        if(key < r->data)
            r->left = Delete(r->left, key);

        else if(key > r->data)
            r->right = Delete(r->right, key);
        else
        {
            //no children
            if(r->left == NULL && r->right == NULL){
                delete r;
                return NULL;
            }
            //1 child right
            else if(r->left == NULL){
                Node* t = r->right;
                delete r;
                return t;
            }
            //1 child left
            else if(r->right == NULL){
                Node* t = r->left;
                delete r;
                return t;
            }
            //2 children use predecessor
            else{
                Node* temp = r->left;
                while(temp->right != NULL)
                    temp = temp->right;

                r->data = temp->data;
                r->left = Delete(r->left, temp->data);
            }
        }
        return r;
    }
    void Delete(int key){
        root = Delete(root, key);
    }
    void Inorder(Node* r){
        if(r == NULL) return;
        Inorder(r->left);
        cout << r->data << " ";
        Inorder(r->right);
    }
};
int main(){
    BST t;
    t.Insert(50);
    t.Insert(30);
    t.Insert(70);
    t.Insert(20);
    t.Insert(40);
    t.Insert(60);
    t.Insert(80);
    cout << "Before delete: ";
    t.Inorder(t.root);
    cout << endl;
    t.Delete(30);
    cout << "After delete:  ";
    t.Inorder(t.root);
    cout << endl;
    return 0;
}
