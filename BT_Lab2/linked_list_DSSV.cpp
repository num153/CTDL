
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser
//cau truc ds sinh vien
//tao, them, nhap, xuat
#include<iostream>

using namespace std;
struct SV{
  string name;
  int id;
  string clss;
  string group;
};
struct Node{
  SV data;
  Node* next;
};
void init(Node *&head){
    head = NULL;
}
Node* createNode(SV &sv){
    Node* p = new Node;
    p->data = sv;
    p->next = NULL;
    return p;
}
bool isEmpty(Node *&head){
    return head == NULL;
}
void addFirst(Node *&head, SV &sv){
    Node* p = createNode(sv);
    p->next = head;
    head = p;
}
void addLast(Node *&head, SV &sv){
    Node *p=createNode(sv);
    if(!isEmpty(head)){
        Node* last = head;
        while(last->next!=NULL){ //last!=NULL la sai vi luc nay last k nam o node cuoi ma no da ra khoi pham vi list roi
            last=last->next;
        }
        last->next = p;
    }else{
        head = p;
    }
}
void nhap1sv(SV &sv){
    cout << "Name: ";
    getline(cin,sv.name);
    cout << "ID: ";
    cin >> sv.id;
    cin.ignore();
    cout << "Class: ";
    getline(cin, sv.clss);
    cout << "Group: ";
    getline(cin,sv.group);
}
void nhapDSsv(Node *&head, SV &sv, int &n){
    cout << "Enter n: ";
    cin >> n; cin.ignore();
    for(int i=0;i<n;i++){
        nhap1sv(sv);
        addLast(head,sv);
    }
}
void xuat1sv(SV sv){
    cout << "Name: " << sv.name << endl;
    cout << "ID: " << sv.id << endl;
    cout << "Class: " << sv.clss << endl;
    cout << "Group: " << sv.group << endl;
}
void xuatDSsv(Node *&head, SV sv, int n){
    Node *flag = head;
    int i=1;
    while(flag!=NULL){
        cout << "\tStudent no." << i << ": \n";
        xuat1sv(flag->data); //chu y cai nay khong phai sv vi no chi dung yen moi bien sv ma thoi chu khong co netx 
        flag=flag->next;
        i++;
    }
}
bool find(string a, string b){
    return a == b;
}
void findStudent(Node*head, SV sv, string s){
    if(!isEmpty(head)){
        Node *flag = head;
        while(flag !=NULL){ // khong su dung flag !=NULL || !find(flag->data.name,s) duoc (chua hieu lam)
            if(find(flag->data.name,s)){
                cout << "\tStudent name " << s << " infor: \n";
                xuat1sv(flag->data); //xuat chu k cout flag->data vi data la mot struct co cac bien .con can truy cap den
                return; //dung lenh nay la dung vong lap duoc roi
            }else{
            flag=flag->next;
            }
        }
        cout << "\tStuden name " << s << " is not found\n";
    }
}
int main()
{
    SV sv1;
    Node* node1;
    int n;
    init(node1);
    nhapDSsv(node1,sv1,n);
    xuatDSsv(node1,sv1,n);
    findStudent(node1,sv1,"nam");
    return 0;
}
