#include<iostream>
#include<vector> 
using namespace std; 
//Create Node 
struct Node { 
 int val; 
Node* left;
 Node* right; 
}; 
Node* createNode(int val) 
{ 
 Node* node = new Node; 
 node->val = val; 
 node->left = NULL; 
 node->right = NULL; 
 return node; 
} 
//Duyet node trong BST 
void preorder(Node* root, vector<int>&v) { 
 if (root == NULL) 
 return; 
 //Them gia tri vao cuoi vector 
 v.push_back(root->val); 
 preorder(root->left, v); 
 preorder(root->right, v); 
} 
int main() { 
 Node* root = createNode(5); 
 root->left = createNode(3); 
 root->right = createNode(7); 
 root->left->left = createNode(2); 
 root->left->right = createNode(4); 
 root->right->left = createNode(6); 
 root->right->right = createNode(8); 
 vector<int>v; 
 //call for preorder. 
 preorder(root, v); 
 int min_diƯ = INT_MAX; 
 int n = v.size(); 
 //Duyet vector va kiem tra gia tri 
 for (int i = 0; i<n; i++) { 
for (int j = i + 1; j<n; j++) {
 int x = abs(v[i] - v[j]); 
 if (min_diƯ > x) {
 min_diƯ = x;
 } 
 } 
 } 
 //In ket qua 
 cout << "the minimum diƯerence is : " << min_diƯ << endl; 
 system("pause"); 
 return 0; 
}
