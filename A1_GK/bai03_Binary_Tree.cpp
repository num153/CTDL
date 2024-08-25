/*
    Chu y duyet LRN can phai co biet visited neu k se bi lap vo han\
*/
#include <fstream>
#include <iostream>
using namespace std;
#define MAX 100
struct Node {
    int data;
    Node *left;
    Node *right;
};
struct Stack {
    Node *a[MAX];
    int top;
};
void initStack(Stack &s) { s.top = -1; }
void pushStack(Stack &s, Node *val) {
    s.top++;
    s.a[s.top] = val;
}
void init(Node *&root) { root = NULL; }
Node *pop(Stack &s) {
    Node *x;
    x = s.a[s.top];
    s.top--;
    return x;
}
Node *peek(Stack &s){
    Node *x = s.a[s.top];
    return x;
}
Node *create(int x) {
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
bool isEmpty(Node *root) { return root == NULL; }
void add(Node *&root, int val) {
    if (isEmpty(root)) {
        root = create(val);
        // root = new Node;
        // root->data = val;
        // root->left = NULL;
        // root->right = NULL;
    } else if (root->data == val) {
        return;
    } else {
        if (val < root->data) {
            return add(root->left, val);
        } else {
            return add(root->right, val);
        }
    }
}
void readFile(Node *&root, const string file) {
    ifstream inFile;
    inFile.open(file);
    if (inFile.is_open()) {
        int val;
        int n;
        inFile >> n;
        inFile.ignore();
        for (int i = 0; i < n; i++) {
            inFile >> val;
            add(root, val);
            inFile.ignore();
        }
        inFile.close();
    } else {
        cout << "Cant open file!\n";
    }
}
void LNR_recursion(Node *root) {
    if (root != NULL) {
        LNR_recursion(root->left);
        cout << root->data << "\t";
        LNR_recursion(root->right);
    }
}
void NLR_recursion(Node *root) {
    if (root != NULL) {
        cout << root->data << '\t';
        NLR_recursion(root->left);
        NLR_recursion(root->right);
    }
}
void LRN_recursion(Node* root){
    if(root!=NULL){
        LRN_recursion(root->left);
        LRN_recursion(root->right);
        cout << root->data << '\t';
    }
}
void LNR_stack(Node *root, Stack &s) {
    if (root != NULL) {
        Node *p = root;
        while (true) {
            while (p != NULL) {
                pushStack(s, p);
                p = p->left;
            }
            if (s.top != -1) {
                Node *r = pop(s);
                cout << r->data << "\t";
                if (r->right != NULL) {
                    p = r->right;
                }
            } else {
                break;
            }
        }
    }
}
void NLR_stack(Node *root, Stack &s) {
    if (root != NULL) {
        Node *p = root;
        while (true) {
            while (p != NULL) {
                cout << p->data << '\t';
                pushStack(s, p);
                p = p->left;
            }
            if (s.top != -1) {
                Node *r = pop(s);
                if (r->right != NULL) {
                    p = r->right;
                }
            } else {
                break;
            }
        }
    }
}
// !!!! truong hop node sau cung phai su dung bien visited
void LRN_stack(Node *root, Stack &s){
    if(root!=NULL){
        Node*p=root;
        Node* visited=NULL;
        while(true){
            while(p!=NULL){
                pushStack(s, p);
                p=p->left;
            }if(s.top!=-1){
                Node*r=peek(s);
                //neu phai ton tai va phai chua duoc duyet
                if(r->right!=NULL && r->right!=visited){
                    p=r->right;
                }else{
                    cout << r->data << '\t';
                    pop(s);
                    visited = r; //node nay duoc duyet roi
                }
            }else{
                break;
            }
        }
    }
}
bool isPrime(int a){
    if(a<2){
        return false;
    }
    for(int i=2;i<a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
void checkPrime(Node* root) {
    if (root != NULL) {
        checkPrime(root->left);
        if (isPrime(root->data)) {
            cout << root->data << "\t";
        }
        checkPrime(root->right);
    }
}
int countNodeWith2Child(Node*root){
    if(root==NULL){
        return 0;
    }
    int count = 0;
    if(root->left!=NULL && root->right!=NULL){
        count = 1;
    }
    count =count + countNodeWith2Child(root->left);
    count =count + countNodeWith2Child(root->right);
    return count;
}
void printNodesWithTwoChildren(Node* root) {
    if (root == NULL) {
        return; // Base case: an empty tree or subtree
    }

    // Check if the current node has both left and right children
    if (root->left != NULL && root->right != NULL) {
        cout << root->data << "\t"; // Print the value of the node
    }

    // Recursively check the left and right subtrees
    printNodesWithTwoChildren(root->left);
    printNodesWithTwoChildren(root->right);
}
int main() {
    Node *tree;
    Stack s1;
    int choice;
    bool f=false;
    init(tree);
    initStack(s1);
    do{
        cout << "\n\t=======MENU========\t\n";
        cout << "1. Read input file\n";
        cout << "2. LNR traversal\n";
        cout << "3. LRN traversal\n";
        cout << "4. NLR traversal\n";
        cout << "5. Print prime node\n";
        cout << "6. Count node with 2 children\n";
        cout << "0. Exit\n";
        cout << "Your choice: "; cin >> choice;
        switch(choice){
            case 1:
            readFile(tree, "input.txt");
            f=true;
            break;
            case 2:
            if(f){
                cout << "LNR stack: ";
                LNR_stack(tree, s1);
            }else{
                cout << "Tree is empty!\n";
            }
            break;
            case 3:
            if(f){
                cout << "LRN stack: ";
                LRN_stack(tree, s1);
            }else{
                cout << "Tree is empty!\n";
            }
            break;
            case 4:
            if(f){
                cout << "NLR stack: ";
                NLR_stack(tree, s1);
            }else{
                cout << "Tree is empty!\n";
            }
            break;
            case 5:
            if(f){
                cout << "Prime node: ";
                checkPrime(tree);
            }else{
                cout << "Tree is empty!\n";
            }
            break;
            case 6:
            if(f){
                int x;
                x=countNodeWith2Child(tree);
                cout << "Count node with 2 children: " << x << endl;
            }else{
                cout << "Tree is empty!\n";
            }
            break;
            case 7:
            if(f){
                cout << "Print node with 2 children: ";
                printNodesWithTwoChildren(tree);
            }else{
                cout << "Tree is empty!\n";
            }
            break;
        }

    }while(choice != 0);
    return 0;
}
