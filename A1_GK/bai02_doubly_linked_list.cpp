#include <iostream>
using namespace std;
struct Node {
  int data;
  Node *next;
  Node *prev;
};
struct Doublell {
  Node *head;
  Node *tail;
};
void init(Doublell &ls) {
  ls.head = NULL;
  ls.tail = NULL;
}
Node *createNode(int x) {
  Node *p = new Node;
  p->data = x;
  p->next = NULL;
  p->prev = NULL;
  return p;
}
bool isEmpty(Doublell ls) { return ls.head == NULL; }
void addFirst(Doublell &ls, int val) {
  Node *p = createNode(val);
  if (isEmpty(ls)) {
    ls.head = p;
    ls.tail = p;
  } else {
    p->next = ls.head;
    ls.head->prev = p;
    ls.head = p;
  }
}
void addLast(Doublell &ls, int val) {
  Node *p = createNode(val);
  if (isEmpty(ls)) {
    ls.head = p;
    ls.tail = p;
  } else {
    p->prev = ls.tail;
    ls.tail->next = p;
    ls.tail = p;
  }
}
void input(Doublell &ls, int &n) {
  cout << "Num. of Node: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    int val;
    cout << "Val no." << i + 1 << ": ";
    cin >> val;
    addLast(ls, val);
  }
}
void output(Doublell ls) {
  if (!isEmpty(ls)) {
    Node *temp = ls.head;
    while (temp != NULL) {
      cout << temp->data << "\t";
      temp = temp->next;
    }
    cout << endl;
  }
}
void countNode(Doublell ls) {
  int count = 0;
  if (!isEmpty(ls)) {
    Node *temp = ls.head;
    while (temp != NULL) {
      temp = temp->next;
      count++;
    }
    cout << "List has " << count << " nodes\n";
  } else {
    cout << "List has 0 node" << endl;
  }
}
Doublell merge(Doublell ls1, Doublell ls2) {
  Doublell ls_merged;
  // Empty ls1, ls2
  if (isEmpty(ls1)) {
    return ls2;
  }
  if (isEmpty(ls2)) {
    return ls1;
  }
  // At least one
  ls1.tail->next = ls2.head;
  ls2.head->prev = ls1.tail;
  ls_merged.head = ls1.head;
  ls_merged.tail = ls2.tail;
  return ls_merged;
}
int main() {
  Doublell ls1;
  Doublell ls2;
  Doublell ls3;
  int n;
  init(ls1);
  init(ls2);
  init(ls3);
  input(ls1, n);
  input(ls2, n);
  output(ls1);
  output(ls2);
  ls3 = merge(ls1, ls2);
  output(ls3);
  countNode(ls3);
  return 0;
}
// - Viết hàm để xoá toàn bộ phần tử danh sách liên kết kép
