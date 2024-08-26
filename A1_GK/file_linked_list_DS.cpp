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
void countPos(Node*head,const string &s){
    Node*temp=head;
    int dem=0;
    Node*result=NULL;
    while(temp!=NULL){
        if(temp->data.pos == s){
            dem++;
            addLast(result,temp->data);
        }
        temp=temp->next;
    }
    cout << dem << endl;
    output(result);
}
void writeFile(Node *head,const string file){
    ofstream f;
    f.open(file);
    if(f.is_open()){
        Node*temp=head;
        while(temp!=NULL){
            f << "Name: " << temp->data.name << endl;
            f << "Salary: " << temp->data.salary << endl;
            f << "Position: " << temp->data.pos << endl;
            f << "Address: " << temp->data.address << endl;
            f << "--------------" << endl;
            temp=temp->next;
        }
        f.close();
    }else{
        cout << "Khong the mo file\n";
    }
}
int main() {
    Node *head,*kq1,*kq2;
    init(head);
    init(kq1);
    init(kq2);
    int choice;
    bool co=false;
    do{
        cout << "\n\t=======MENU======\t\n";
        cout << "1. Read input file\n";
        cout << "2. Print\n";
        cout << "3. Find name\n";
        cout << "4. Find salary\n";
        cout << "5. Sort salary\n";
        cout << "6. Sort name and address\n";
        cout << "7. Count position\n";
        cout << "8. Write output file\n";
        cout << "9. Delete all\n";
        cout << "0. Exit\n";
        cout << "Your choice: "; cin >> choice;
        switch(choice){
            case 1:
                readFile(head, "nhanvien.txt");
                co=true;
                break;
            case 2:
            if(co){
                output(head);
            }else{
                cout << "Empty list!\n";
            }
            break;
            case 3:
            if(co){
                cout << "\nDS co ten Nam\n";
                kq1=searchName(head, "Nam");
                output(kq1);
            }else{
                cout << "Empty list!\n";
            }
            break;
            case 4:
            if(co){
                cout << "\nDS co luong tu 50 den 100\n";
                kq2=searchSalary(head, 50,100);
                output(kq2);
            }else{
                cout << "Empty list!\n";
            }
            break;
            case 5:
            if(co){
                cout <<"\nSap xep luong giam\n";
                sortSalary(head, des);
                output(head);
            }else{
                cout << "Empty list!\n";
            }
            break;
            case 6:
            if(co){
                cout <<"\nSap xep dia chi giam (hoac ten tang)\n";
                sortNameAddress(head, desString);
                output(head);
            }else{
                cout << "Empty list!\n";
            }
            break;
            case 7:
            if(co){
                countPos(head, "Giam doc");
            }else{
                cout << "Empty list!\n";
            }
            break;
            case 8:
            if(co){
                writeFile(kq1, "nhanvien_ten.txt");
            }else{
                cout << "Empty list!\n";
            }
            break;
            case 9:
            if(co){
                free(head);
            }
            if(!isEmpty(kq1)){
                free(kq1);
            }
            if(!isEmpty(kq2)){
                free(kq2);
            }
            break;
        }
    }while(choice!=0);
    return 0;
}
