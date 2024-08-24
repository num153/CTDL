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
int main() {
    Node *tree;
    Stack s1;
    init(tree);
    initStack(s1);
    readFile(tree, "input.txt");
    LNR_recursion(tree);
    cout << "\nLNR stack:\n";
    LNR_stack(tree, s1);
    cout << "\nNLR:\n";
    NLR_recursion(tree);
    cout << "\nNLR:\n";
    NLR_stack(tree, s1);
    return 0;
}
