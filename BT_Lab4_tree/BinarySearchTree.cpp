/*
	Chu y de quy sum (return 0)
	Ham xoa co 3 case
	Thu tu left right cua ham findRepNode
*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node*left;
	Node*right;
};
void init(Node*&root) {
	root = NULL;
}
void add(Node*&root, int x) {
	//neu rong
	if (root == NULL) {
		root = new Node;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}
	//neu x == root
	else if (root->data == x) {
		return;
	}
	//else
	else
	{
		if (x < root->data) {
			return add(root->left, x);
		}
		else {
			return add(root->right, x);
		}
	}
}
void findRepNode(Node*&p, Node*&q) {
	if (q->left != NULL) {
		findRepNode(p, q->left);
	}
	else
	{
		p->data = q->data;
		p = q;
		q = q->right;
	}
}

void del(Node*&root, int x) {
	if (root == NULL) {
		return;
	}
	if (x < root->data) {
		return del(root->left, x);
	}
	if (x > root->data) {
		return del(root->right, x);
	}
	// x be founded
	if (root->data == x) {
		Node*p = root;
		//x chi co 1 node trai
		if (root->right == NULL) {
			root = root->left;
		}
		//x chi co 1 node phai
		else if (root->left == NULL) {
			root = root->right;
		}
		// x co hai node
		else {
			findRepNode(p, root->right);
		}
		delete p;
	}
}
void LNR_traversal(Node *root) {
	if (root != NULL) {
		LNR_traversal(root->left);
		cout << root->data << "\t";
		LNR_traversal(root->right);
	}
}
Node* search(Node*root, int x) {
	if (root != NULL) {
		if (root->data == x) {
			return root;
		}
		else
		{
			if (x < root->data) {
				return search(root->left,x);
			}
			else {
				return search(root->right,x);
			}
		}
	}
	return NULL;
}
int sum(Node*root) {
	if (root == NULL) {
		return 0; //chu y khong quen truong hop nay
	}
	else {
		return root->data + sum(root->left) + sum(root->right);
	}
}
int countNode(Node*root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + countNode(root->left) + countNode(root->right);
}
int findMin(Node*root) {
	if (root != NULL) {
		if (root->left == NULL) {
			return root->data;
		}
		else {
			findMin(root->left);
		}
	}
}
int findMax(Node*root) {
	if (root != NULL) {
		if (root->right == NULL) {
			return root->data;
		}
		else {
			findMax(root->right);
		}
	}
}
int main() {
	Node *r;
	init(r);
	add(r, 5);
	add(r, 10);
	add(r, 33);
	add(r, 30);
	add(r, 35);
	LNR_traversal(r);
	cout << search(r, 10) << endl;
	del(r, 33);
	LNR_traversal(r);
	cout << "\nTong cay: " << sum(r);
	cout << "\nMin: " << findMin(r);
	cout << "\nMax: " << findMax(r);
	cout << "\nSo luong node: " << countNode(r);
	system("pause");
	return 0;
}
