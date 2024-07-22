/*
  Chu y case khi BST khong co node nao
*/
#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};
//chu y lam on dung quen truyen tham chieu, lam onnn
void init(Node*& root){
  root = NULL;
}
Node *createNode(int x){
  Node *p = new Node;
  p->data = x;
  p->left = NULL;
  p->right = NULL;
  return p;
}
void insertNode(Node *&root, int val){
  if (root == NULL) {
        root = createNode(val);
        return;
    }
  Node* p = root;
  Node* prev = NULL;
  while(p!=NULL && p->data!=val){
    prev = p;
    if(val<p->data){
      p=p->left;
    }else{
      p=p->right;
    }
  }
  if(p==NULL){
    p=createNode(val);
    if(prev->data < val){
      prev->right = p;
    }else{
      prev->left = p;
    }
  }
}
void lnrTraversal(Node* root) {
    if(root!=NULL){
      lnrTraversal(root->left);
      cout << root->data << "\t";
      lnrTraversal(root->right);
    }
}

int main() 
{
    Node *root;
    init(root);
    insertNode(root,20);
    insertNode(root,45);
    insertNode(root,30);
    insertNode(root,15);
    lnrTraversal(root);
    return 0;
}
