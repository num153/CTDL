#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Nhanvien {
  string name;
  double salary;
  string pos;
  string address;
};
struct Node {
  Nhanvien data;
  Node *next;
};
void init(Node *&head) { head = NULL; }
bool isEmpty(Node *head) { return head == NULL; }
Node *create(Nhanvien nv) {
  Node *p = new Node;
  p->data = nv;
  p->next = NULL;
  return p;
}
void addLast(Node *&head, Nhanvien nv) {
  Node *p = create(nv);
  if (isEmpty(head)) {
    head = p;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = p;
  }
}
void addFirst(Node *&head, Nhanvien val) {
  Node *p = create(val);
  // list rong
  if (isEmpty(head)) {
    head = p;
  } else {
    // list > 2 node
    p->next = head;
    head = p;
  }
}
void readFile(Node *&head, const string file) {
  ifstream inFile;
  inFile.open(file);
  if (inFile.is_open()) {
    Nhanvien nv;
    while (!inFile.eof()) {
      getline(inFile, nv.name);
      inFile >> nv.salary;
      inFile.ignore();
      getline(inFile, nv.pos);
      getline(inFile, nv.address);
      addFirst(head, nv);
    }
    inFile.close();
  } else {
    cout << "Khong the mo file\n";
  }
}
void outputNV(Nhanvien nv) {
  cout << "Name: " << nv.name << endl;
  cout << "Salary: " << nv.salary << endl;
  cout << "Position: " << nv.pos << endl;
  cout << "Address: " << nv.address << endl;
}
void output(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    outputNV(temp->data);
    temp = temp->next;
  }
}
int main() {
  Node *head;
  init(head);
  cout << "Chya";
  readFile(head, "nhanvien.txt");
  output(head);
  return 0;
}
