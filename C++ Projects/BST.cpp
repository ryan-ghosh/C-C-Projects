#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
    int value;
    Node *left;
    Node *right;
    Node *parent;
    Node(int avalue, Node *aleft=0, Node *aright=0, Node *aparent=0){
        value = avalue;
        left = aleft;
        right = aright;
        parent = aparent;
    }
};

class BST{
    public:
    Node *root;
    BST(Node *aroot){
        root = aroot;
    }
    void insert(Node *v, Node *curr=NULL){
        if(curr){
            curr = curr;
        }else{
            curr = root;
        }if(curr==NULL){
            curr = v;
        }if(v->value < curr->value){
            if(curr->left){
                insert(v, curr->left);
            }else{
                v->parent = curr;
                curr->left = v;
            }
        }if(v->value > curr->value){
            if(curr->right){
                insert(v, curr->right);
            }else{
                v->parent = curr;
                curr->right = v;
            }
        }
    }
    bool search(int val, Node *curr=NULL){
        if(curr){
            curr = curr;
        }else{
            curr = root;
        }if(curr->value == val){
            return true;
        }if(!curr->right && !curr->left){
            return false;
        }if(val < curr->value){
            return search(val, curr->left);
        }if(val > curr->value){
            return search(val, curr->right);
        }
    }
};

int main(){
    Node first = Node(5);
    Node second = Node(7);
    Node third = Node(3);
    Node fourth = Node(1);
    Node fifth = Node(9);
    BST tree = BST(&first);
    tree.insert(&second);
    tree.insert(&third);
    tree.insert(&fourth);
    tree.insert(&fifth);
    cout << first.right->value << endl;
    cout << first.left->value << endl;
    cout << tree.search(5) << endl;
    cout << tree.search(7) << endl;
    cout << tree.search(3) << endl;
    cout << tree.search(1) << endl;
    cout << tree.search(9) << endl;
    cout << tree.search(10) << endl;

}