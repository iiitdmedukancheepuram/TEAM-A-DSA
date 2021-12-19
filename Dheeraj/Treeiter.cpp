#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
    Node() {};
    Node(int data);
};
 
Node::Node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}
 
class Tree{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void CreateTree();
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
    int Height(Node* p);
    int Height() { return Height(root); }
    int Count(Node* p);
    int Count(){ Count(root); }
    int countLeaf(Node *p);
    int countLeaf(){ countLeaf (root); }
};
 
Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {
    // TODO
}
 
void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;
 
    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }
 
        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

 
void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << p->data << ", " << flush;
    q.emplace(p);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }
 
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}
 
void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}
 
void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}
 
void Tree::iterativePostorder(Node *p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace((long int)p);
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
 
    if (p != nullptr){
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r){
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return 0;
}
 
int Tree::Count(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Tree::countLeaf(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = countLeaf(p->lchild);
        y = countLeaf(p->rchild);
        
        if(p->lchild == NULL && p->rchild == NULL)
        {
              return x +y+1;
        }
        else{
              return x+y;
        }
    }
    return 0;
} 
 
int main() {
 
    Tree bt;
 
    bt.CreateTree();
    cout<<endl<<endl;
    
    cout << "Preorder: " << flush;
    bt.iterativePreorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.iterativeInorder();
    cout << endl;
    
    cout << "Postorder: " << flush;
    bt.iterativePostorder();
    cout << endl;
 
 
    cout << "Height: " << bt.Height() << endl;
    
     cout << "count total nodes: " <<bt.Count()<<endl;
    cout<< "leaf nodes are: "<<bt.countLeaf()<<endl; 
    
    return 0;
}
