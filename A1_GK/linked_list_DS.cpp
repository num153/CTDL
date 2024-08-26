/*
    Chu y file txt lam on dung dum
    Ham search tra ve ds chu k phai node mat cong add
    Ham sort phai dung funct, trong main khong can ()
*/
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
void free(Node *&head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
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
    Nhanvien nv;
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            getline(inFile, nv.name);
            inFile >> nv.salary;
            inFile.ignore();
            getline(inFile, nv.pos);
            getline(inFile, nv.address);
            addLast(head, nv);
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
    cout << "-----------------\n";
}
void output(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        outputNV(temp->data);
        temp = temp->next;
    }
}
Node *searchName(Node *head, string keyword) {
    Node *result;
    init(result);
    Node *p = head;
    while (p != NULL) {
        if (p->data.name.find(keyword) !=
                string::npos) { //!= la pos cua keyword khac voi max size cua string
                                                //!-->//!tim thay trong string
            addLast(result, p->data);
        }
        p = p->next; // khong su dung else, vi no se k chay tiep dc
    }
    return result;
}
Node *searchSalary(Node *head, double rangeA, double rangeB) {
    Node *result;
    init(result);
    Node *p = head;
    while (p != NULL) {
        if (p->data.salary >= rangeA && p->data.salary <= rangeB) {
            addLast(result, p->data);
        }
        p = p->next;
    }
    return result;
}
bool des(double a, double b) { return a > b; }
bool desString(string a, string b) { return a > b; }
void sortSalary(Node *head, bool funct(double a, double b)) {
    for (Node *i = head; i->next != NULL; i = i->next) {
            for(Node*j=i->next;j!=NULL;j=j->next){
                    if(!funct(i->data.salary, j->data.salary)){ //!des(i->data.salary, j->data.salary) NGUUUU
                            swap(i->data, j->data);
                    }
            }
    }
}
void sortNameAddress(Node*head,bool funct(string a, string b)){
    for (Node *i = head; i->next != NULL; i = i->next) {
            for(Node*j=i->next;j!=NULL;j=j->next){
                    if(!funct(i->data.address, j->data.address)){ 
                            swap(i->data, j->data);
                    }else if(i->data.address == j->data.address){
                        if(funct(i->data.name, j->data.name)){
                            swap(i->data, j->data);
                        }
                    }
            }
    }
    
}
int main() {
    Node *head;
    init(head);
    readFile(head, "nhanvien.txt");
    output(head);
    cout << "\t\tDS Nhan vien co ten Nam\n";
    Node *kq;
    init(kq);
    kq = searchName(head, "Nam");
    output(kq);
    cout << "\t\tDS Nhan vien co luong tu 50 den 100\n";
    Node *kq2;
    kq2 = searchSalary(head, 50, 100);
    output(kq2);
    cout << "\n\tSap xep giam dan theo luong: \n";
    sortSalary(head, des);
    output(head);
    cout << "\n\tSap xep giam dan theo que quan (hoac tang dan theo ten): \n";
    sortNameAddress(head, desString);
    output(head);
    free(head);
    free(kq);
    free(kq2);
    return 0;
}
